class Solution {
public:
    int jump(vector<int>& nums) {
        int n = 0;
        int f = 0;
        int jumps = 0;

        while(f < nums.size()-1) {
            int ft = 0;
            for(int i = n; i<=f; i++) {
                ft = max(ft, i + nums[i]);
            }
            n = f +1 ;
            f = ft;
            jumps++;
        }

        return jumps;
    }
};