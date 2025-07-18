class Solution {
public:
    using ll = long long;
    void dfs1(int u, int p, vector<vector<int>>& adj, vector<ll>& sum, vector<int>& cost) {
        for(int v : adj[u]) {
            if(v == p) continue;
            sum[v] = sum[u] + cost[v];
            dfs1(v, u, adj, sum, cost);
        }
    }

    ll dfs2(int u, int p, vector<ll>& arr, vector<ll>& sum, int target, vector<vector<int>>& adj) {
        bool isleaf = true;
        ll mini = LLONG_MAX;
        for(int v : adj[u]) {
            if( v == p) continue;
            isleaf = false;
            mini = min(mini, dfs2(v, u, arr, sum, target, adj));
        }

        if(isleaf == true) {
            mini = target - sum[u];
        }

        return arr[u] = mini;
    }

    void dfs3(int u, int p, int& ans, vector<ll>& arr, vector<vector<int>>& adj) {
        ll parent = 0;
        if(p == -1) {
            parent = 0LL; 
        } else {
            parent = arr[p];
        }

        if(arr[u] > parent) {
            ans++;
        }

        for(int v : adj[u]) {
            if(v == p)continue;
            dfs3(v, u, ans, arr,adj);
        }
    }



    int minIncrease(int n, vector<vector<int>>& edges, vector<int>& cost) {
        
        vector<vector<int>> adj(n);
        for(auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<ll> sum(n, 0);
        sum[0] = cost[0];
        dfs1(0, -1, adj, sum, cost);

        ll target = LLONG_MIN;
        for(int u = 0; u<n; u++) {
            bool leaf = (u == 0 ? adj[u].empty() : adj[u].size() == 1);
            if(leaf)
                target = max(target, sum[u]);
        }

        vector<ll> arr(n, 0);
        int ans = 0;
        dfs2(0, -1, arr, sum, target, adj);
        dfs3(0, -1, ans, arr, adj);

        return ans;

    }
};