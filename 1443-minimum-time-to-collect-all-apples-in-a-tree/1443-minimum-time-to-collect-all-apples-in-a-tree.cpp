class Solution {
public:
    int f(vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& hasApple, int node) {
        if(visited[node] == true) return 0;
        
        visited[node] = true;
        int time = 0;
        for(auto nei : adj[node]) {
            time += f(adj, visited, hasApple, nei);
        }

        if(node == 0) return time;
        if(hasApple[node] || time > 0) {
            return time+2;
        }
        return 0;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);
        for(auto& edge: edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);
        return f(adj, visited, hasApple, 0);
    }
};