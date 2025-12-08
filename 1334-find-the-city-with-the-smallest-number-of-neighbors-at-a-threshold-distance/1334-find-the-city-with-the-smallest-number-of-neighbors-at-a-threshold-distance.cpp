class Solution {
public:
    int dijistra(int n, vector<vector<pair<int, int>>>& adj, int start, int thres) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0, start});

        vector<int> dist(n, INT_MAX);
        dist[start] = 0;

        int count = 0;

        while(!q.empty()) {
            auto p = q.top(); q.pop();
            int till_dist = p.first;
            int node = p.second;

            for(auto nei: adj[node]) {
                int nextnode = nei.first;
                int wei = nei.second;

                if(till_dist + wei < dist[nextnode]) {
                    dist[nextnode] = till_dist + wei;
                    q.push({till_dist + wei, nextnode});
                }
            }
        }

        for(int i = 0; i<n; i++) {
            if(i != start && dist[i] <= thres) count++;
        }

        return count;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int, int>>> adj(n);

        for(auto edge: edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});

        }
        
        int ans = INT_MIN;
        int mini = INT_MAX;
        for(int i= 0; i<n; i++) {
            // need to get the smallest number of cities reachable
            int number_of_cities_reachable = dijistra(n, adj, i, distanceThreshold);
            // cout << i << " " << number_of_cities_reachable << endl;
            if(number_of_cities_reachable <= mini) {
                mini = number_of_cities_reachable;
                ans = max(ans, i);
            }
        }

        return ans;
    }
};