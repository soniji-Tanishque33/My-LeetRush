class Solution {
public:
    int f(string time) {
        string hr = time.substr(0, 2);
        string min = time.substr(3, 2);
        int ans = stoi(hr) * 60 + stoi(min);
        cout << ans << endl;
        return ans;
    }
    int findMinDifference(vector<string>& timePoints) {
        int ans = INT_MAX;
        int n = timePoints.size();

        sort(timePoints.begin(), timePoints.end());

        for(int i = 0; i<timePoints.size()-1; i++) {
            ans = min(ans, f(timePoints[i+1]) - f(timePoints[i]));
        }

        cout << "ans after for " << ans << endl;

        int last_first = f(timePoints[n-1]) - f(timePoints[0]);
        last_first = min(last_first % 1440, (1440-last_first) % 1440);

        cout << "last - first " << last_first << endl;
        ans = min(last_first, ans);
        ans = min(ans % 1440, (1440-ans) % 1440);
        return ans;
    }
};