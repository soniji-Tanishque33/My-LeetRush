class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
       deque<pair<int, int>> dq;
       int ans = INT_MIN;

       for(int i = 0; i<points.size(); i++) {
            while(!dq.empty() && points[i][0] - dq.front().second > k) {
                dq.pop_front();
            }
            if(!dq.empty()) {
                ans = max(ans, points[i][0] + points[i][1] + dq.front().first);
            }
            while(!dq.empty() && points[i][1] - points[i][0] > dq.back().first) {
                dq.pop_back();
            }
            dq.push_back({points[i][1] - points[i][0], points[i][0]});
       }

       return ans;
    }
};