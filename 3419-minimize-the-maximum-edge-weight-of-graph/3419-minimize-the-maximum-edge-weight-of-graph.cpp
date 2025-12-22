class Solution {
public:
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        unordered_map<int, vector<pair<int, int>>> graph;

        for(auto& edge: edges) {
            int start = edge[0];
            int end = edge[1];
            int wt = edge[2];

            graph[end].push_back({wt, start});
        }

        vector<bool> visited(n, false);
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq; // minheap
        pq.push({0, 0}); // weight, node;
        int mx = 0;

        while(pq.size() > 0) {
            auto top = pq.top(); pq.pop();
            int wt = top[0];
            int node = top[1];

            if(visited[node] == true) continue;
            visited[node] = true;
            mx = max(wt, mx);

            for(auto& nei : graph[node]) {
                if(visited[nei.second] == false) pq.push({nei.first, nei.second});
            }
        }

        for(auto b : visited) if(b == false) return -1;
        return mx;


    }
};