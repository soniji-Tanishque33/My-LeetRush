class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        priority_queue<int> pq;

        vector<vector<int>> ans;

        vector<pair<int, int>> points;

        for(auto building : buildings) {
            int s = building[0];
            int e = building[1];
            int h = building[2];
            points.push_back({s, -h});
            points.push_back({e, h});
        }

        sort(points.begin(), points.end());
        
        pq.push(0);
        int maxh = 0;
        unordered_map<int, int> toremove;

        for(auto& [x, h] : points) {
            if(h < 0) {
                pq.push(-h);
            } else {
                toremove[h]++;
            }

            while(pq.size() && toremove[pq.top()] > 0) {
                toremove[pq.top()]--;
                pq.pop();
            }

            int curr = pq.top();
            if(maxh != curr) {
                ans.push_back({x, curr});
                maxh = curr;
            }

        }

        return ans;

    }
};

// Input: buildings = [[2,9,10],[3,7,15],[5,12,12],[15,20,10],[19,24,8]]
// 2 -10    3 -15   5 -12   7 15
// 