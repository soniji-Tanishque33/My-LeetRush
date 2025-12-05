class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> mp; // node -> {neig, weight}

        for(auto& t : times) {
            mp[t[0]].push_back({t[1], t[2]});
        }

        vector<int> dist(n+1, INT_MAX);
        // take the other things from index 1
        dist[k] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});

        while(!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            int time = top.first;
            int node = top.second;

            for(auto it : mp[node]) {
                int nei = it.first;
                int wt = it.second;
                if(time + wt < dist[nei]) {
                    dist[nei] = time + wt;
                    pq.push({dist[nei], nei});
                }
            }

        }
        int maxi = INT_MIN;
        for(int i = 1; i<=n; i++) {
            if(dist[i] == INT_MAX) return -1;
            maxi = max(maxi, dist[i]);
        }

        return maxi;

    }
};