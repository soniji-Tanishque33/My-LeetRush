
class Solution {
public:
    map<int, vector<int>> createGraph(int numVertices, vector<vector<int>>& edges) {
        map<int, vector<int>> mp;
        for(int i = 0; i<numVertices; i++) {
            mp[i] = {};
        }

        for(auto edge : edges) {
            mp[edge[1]].push_back(edge[0]);
        }

        return mp;
    }

    bool checkCycle(int node, map<int, vector<int>>& graph, vector<int>& visited, vector<int>& dfsVisited) {
        visited[node] = 1;
        dfsVisited[node] = 1;

        for(auto adjNode : graph[node]) {
            if(!visited[adjNode]) {
                if(checkCycle(adjNode, graph, visited, dfsVisited)) return true;
            }
            else if(dfsVisited[adjNode]) return true;
        }
        dfsVisited[node]= 0;
        return false;
    }
// we need a directed graph
// [a, b] => b -> a
// now we need to see if there is a cycle
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        map<int, vector<int>> graph = createGraph(numCourses, prerequisites);
        vector<int> visited(numCourses, 0);
        vector<int> dfsVisited(numCourses, 0);

        for(int i = 0; i<numCourses; i++) {
            if(!visited[i])
                if(checkCycle(i, graph, visited, dfsVisited)) return false;
        }

        return true;


    }
};