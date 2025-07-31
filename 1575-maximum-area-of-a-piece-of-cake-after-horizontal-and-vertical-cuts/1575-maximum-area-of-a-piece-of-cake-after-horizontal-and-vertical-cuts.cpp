class Solution {
public:
    using lli = long long int;
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        const lli mod = 1000000007;
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());

        vector<int> horizontal_lengths = {horizontalCuts[0]};
        int hh = horizontalCuts.size();
        for(int i = 1; i<horizontalCuts.size(); i++) {
            horizontal_lengths.push_back(horizontalCuts[i] - horizontalCuts[i-1]);
        }
        horizontal_lengths.push_back(h-horizontalCuts[hh-1]);

        int vv = verticalCuts.size();
        vector<int> vertical_lengths = {verticalCuts[0]};

        for(int i = 1; i<vv; i++) {
            vertical_lengths.push_back(verticalCuts[i] - verticalCuts[i-1]);
        }
        vertical_lengths.push_back(w - verticalCuts[vv-1]);

        lli a = *max_element(horizontal_lengths.begin(), horizontal_lengths.end());
        lli b = *max_element(vertical_lengths.begin(), vertical_lengths.end());

        return (int) ((a*b) % mod);
    }
};