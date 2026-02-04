class Solution {
public:
    int countMonobit(int n) {
        int ans = 0;
        int i = 0;
        while((1 << ans) - 1 <= n) {
            ans++;
        }
        return ans;
    }
};