class Solution {
public:
    bool cycle(int node, vector<int>& color, vector<vector<int>>& adj) {
        if(color[node] == 0) {
            color[node] = 1;
        }

        for(int child : adj[node]) {
            if(color[child] == 0) {
                color[child] = -1 * color[node];
                if(cycle(child, color, adj)) return true;
            } 
            else if (color[child] == color[node]) return true;
        }
        
        return false;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n+1);

        for(int i = 0; i<dislikes.size(); i++) {
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
        }   

        vector<int> color(n+1, 0);

        for(int i = 1; i<=n; i++) {
            if(color[i] == 0) {
                if(cycle(i, color, adj)) return false;
            }
        }

        return true;
    }
};