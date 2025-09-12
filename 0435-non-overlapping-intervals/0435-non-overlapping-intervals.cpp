class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        int last = INT_MIN;
        int count = 0;
        for(auto& interval : intervals) {
            if(last > interval[0]) {
                count++;
            } else {
                last = interval[1];
            }

        }
        return count;
    }
};