class Solution {
public:

    bool dfs(int node, vector<int>& visited, vector<vector<int>>& graph) {
        if(visited[node] != -1) return visited[node] == 1;

        visited[node] = 0;

        for(int nei : graph[node]) {
            if(dfs(nei, visited, graph) == false) return false;
        }

        visited[node] = 1;
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> ans;
        vector<int> visited(n, -1);
        for(int i = 0; i<n; i++) {
            if(dfs(i, visited, graph)) ans.push_back(i);
        }

        return ans;
    }
};