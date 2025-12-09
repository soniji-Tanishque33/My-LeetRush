class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);

        for(auto flight: flights) {
            int start = flight[0];
            int end = flight[1];
            int cost = flight[2];

            adj[start].push_back({end, cost});
        }

        queue<pair<int, int>> q;

        q.push({0, src});
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        int stop = 0;
        int ans = INT_MAX;
        while(!q.empty() && stop <= k) {
            int size = q.size();
            while(size--) {
                auto top = q.front();
                q.pop();

                int node = top.second;
                int till_cost = top.first;
    
                for(auto nei : adj[node]) {
                    int nextnode = nei.first;
                    int nextcost = nei.second;
                    if(till_cost + nextcost < dist[nextnode]) {
                        dist[nextnode] = till_cost + nextcost;
                        q.push({till_cost + nextcost, nextnode});
                    }
                }
            }
            stop++;
        }

        if(dist[dst] == INT_MAX) return -1;
        return dist[dst];
    }
};