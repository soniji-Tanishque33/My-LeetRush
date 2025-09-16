class Solution {
public:

    bool dfs(int i, vector<bool>& visited, vector<bool>& path, vector<vector<int>>& graph, vector<int>& res) {
        if(visited[i] == true) return true;
        if(path[i] == true) return false;
        
        path[i] = true;
        for(int adj : graph[i]) {
            if(visited[adj] == false) {
                if(dfs(adj, visited, path, graph, res) == false) return false;
            }
        }

        path[i] = false;
        visited[i] = true;
        res.push_back(i);

        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for(auto& p : prerequisites) {
            int u = p[0];
            int v = p[1];
            graph[v].push_back(u);
        }

        vector<bool> visited(numCourses, false);
        vector<bool> path(numCourses, false);

        vector<int> res;

        for(int i = 0; i<numCourses; i++) {
            if(visited[i] == false) {
                if(dfs(i, visited, path, graph ,res) == false) return {};
            }
        }

        reverse(res.begin(), res.end());

        return res;

    }
};