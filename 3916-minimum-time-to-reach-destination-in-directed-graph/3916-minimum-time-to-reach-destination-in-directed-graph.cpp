class Solution {
public:
    
    using vt = vector<int>;
    int minTime(int n, vector<vector<int>>& edges) {
        vector<vector<vt>> g(n);
        for(auto& edge: edges) {
            g[edge[0]].push_back({edge[1], edge[2], edge[3]});
        }

        // pq -> {time taken to visit that node, node}
        priority_queue<vt, vector<vt>, greater<vt>> pq; // minheap

        pq.push({0, 0}) ;
        vector<int> dist(n, INT_MAX);
        dist[0] = 0;

        int time = 0;
        while(!pq.empty()) {
            vector<int> node = pq.top(); 
            pq.pop();
            int time = node[0];
            int v = node[1];
            for(auto& edge: g[v]) {
                if(time > edge[2]) continue;
                int t1 = max(time, edge[1]) + 1;
                if(t1 < dist[edge[0]]) {
                    dist[edge[0]] = t1;
                    pq.push({t1, edge[0]});
                }
            }


        }

        return dist[n-1] == INT_MAX ? -1 : dist[n-1];
    }   
};