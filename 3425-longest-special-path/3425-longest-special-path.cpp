class Solution {
public:
    vector<vector<pair<int, int>>> adj;
    vector<pair<int, int>> dp; // {kitni max len till index, kitne min nodes till index}
    unordered_map<int, pair<int, int>> last; // color-> root se kitni len, kitne nodes
    vector<int> val;
    vector<pair<int, int>> lim; // root se kitni door, last node kya tha

    void dfs(int v, int par, int node, int len) {
        if(par == -1) {
            // if this is root node => initialize all the variables and proceed to neighbors
            dp[v] = make_pair(0, 1);
            lim[v] = make_pair(0, -1);
            last[val[v]] = make_pair(0, 0);

            for(auto& nei : adj[v]) {
                int next = nei.first;
                int wt = nei.second;
                last[val[v]].first += wt;
                if(next != par) dfs(next, v, node+1, len+wt);
                last[val[v]].first -= wt;
            }

            last.erase(val[v]);
        } else {
            // if it is not a root node
            //      if it has already been seen:
            //          - make the limit as the max of last seen and limit of parent
            //          - dp[v] = len - lim.first, node - lim.second
            //          - then dfs the neighbors
            //      else
            //          - dp[v] = len - lim.first, node - lim.second
            //          - dfs the neighbors

            if(last.find(val[v]) != last.end()) {
                lim[v] = max(lim[par], last[val[v]]);
                dp[v] = make_pair(len - lim[v].first, node - lim[v].second);
                auto temp = last[val[v]];
                last[val[v]] = make_pair(len, node);

                for(auto& nei : adj[v]) {
                    int next = nei.first;
                    int wt = nei.second;
                    last[val[v]].first += wt;
                    if(next != par) dfs(next, v, node+1, len + wt);
                    last[val[v]].first -= wt;
                }

                last[val[v]] = temp;
                return;
            } else {
                lim[v] = lim[par];
                dp[v] = make_pair(len - lim[v].first, node - lim[v].second);
                last[val[v]] = make_pair(len, node);

                for(auto& nei : adj[v]) {
                    int next= nei.first;
                    int wt = nei.second;
                    last[val[v]].first += wt;
                    if(next != par) dfs(next, v, node+1, len+wt);
                    last[val[v]].first -= wt;
                }

                last.erase(val[v]);
                return ;

            }
        }
    }


    vector<int> longestSpecialPath(vector<vector<int>>& edges, vector<int>& nums) {
        int n = nums.size();

        adj.resize(n);
        dp.resize(n);
        lim.resize(n);
        val = nums;


        for(auto& edge: edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }

        dfs(0, -1, 0, 0);

        pair<int, int> ans = dp[0];

        for(int i =1; i<n; i++) {
            if(ans.first < dp[i].first) {
                ans = dp[i];
            } 
            else if(ans.first == dp[i].first && ans.second > dp[i].second) {
                ans = dp[i];
            }
        }


        return vector<int>({ans.first, ans.second});





    }
};