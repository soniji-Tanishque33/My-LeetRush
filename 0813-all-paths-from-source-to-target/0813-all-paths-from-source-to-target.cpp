class Solution {
public:
    void dfs(int start, int end, vector<int>& temp, vector<vector<int>>& ans, vector<int>& visited, vector<vector<int>>& graph) {
        visited[start] = 1;
        temp.push_back(start);
        if(start == end) {
            ans.push_back(temp);
        }
        for(int nei : graph[start]) {
            if(visited[nei] == 0) {
                dfs(nei, end, temp, ans, visited, graph);
            }
        }
        visited[start] = 0;
        temp.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int start = 0;
        int n = graph.size();
        vector<vector<int>> ans;
        vector<int> temp;
        vector<int> visited(n, 0);

        dfs(start, n-1, temp, ans, visited, graph);

        return ans;
    }
};