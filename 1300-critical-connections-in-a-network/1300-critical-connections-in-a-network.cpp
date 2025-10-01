class Solution {
private:
    int timer = 1;

    void dfs(int node, int parent, int tim[], int low[], vector<int>& visited, vector<vector<int>>& adj, vector<vector<int>>& ans) {
        
        visited[node] = 1;
        tim[node] = timer;
        low[node] = timer;
        timer++;
        for(int nei : adj[node]) {
            if(nei == parent) continue;
            if(visited[nei] == 0) {
                dfs(nei, node, tim, low, visited, adj, ans);
                low[node] = min(low[node], low[nei]);
                if(low[nei] > tim[node]) {
                    ans.push_back({node, nei});
                }
            } else {
                low[node] = min(low[node], low[nei]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(int i =0; i<connections.size(); i++) {
            int u = connections[i][0];
            int v = connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int tim[n];
        int low[n];
        vector<int> visited(n, 0);
        vector<vector<int>> ans;
        dfs(0, -1, tim, low, visited, adj, ans);

        return ans;

    }
};