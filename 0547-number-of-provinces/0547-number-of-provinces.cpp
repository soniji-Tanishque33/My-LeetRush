class Solution {
public:
    void dfs(int start, unordered_map<int, set<int>>& g, vector<int>& visited) {
        if(visited[start] == 1) return;
        visited[start] = 1;

        for(int ne : g[start]) {
            if(visited[ne] == 0) {
                dfs(ne, g, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected[0].size();
        vector<int> visited(n, 0);

        unordered_map<int, set<int>> g;
        for(int i = 0; i<isConnected.size(); i++) {
            for(int j = 0; j<n; j++) {
                if(isConnected[i][j] == 1 && i != j) {
                    g[i].insert(j);
                    g[j].insert(i);
                }
            }
        }

        int ans = 0;
        for(int i = 0; i<n; i++) {
            if(visited[i] == 0) {
                dfs(i, g, visited);
                ans++;
            }
        }

        return ans;
    }
};