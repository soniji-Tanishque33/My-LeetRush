class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        for(int x: nums) sum += x;
        int n = *max_element(nums.begin(), nums.end());

        int exp_sum = n*(n+1)/2;
        if(exp_sum == sum) {
            if(*min_element(nums.begin(), nums.end()) == 0) return n+1;
            else return 0;
        }
        return exp_sum-sum;
    }
};