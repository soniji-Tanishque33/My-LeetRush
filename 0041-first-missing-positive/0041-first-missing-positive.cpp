class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // replace all the -ve and values greater than len(nums) -> len(nums)
        // mark the indices in the array itself
        // then the values that are positive ans = i+1

        int n = nums.size();
        for(int i = 0; i<n; i++) {
            if(nums[i] <= 0 || nums[i] > n) {
                nums[i] = n+1;
            }
        }

        for(int i = 0; i<n; i++) {
            int num = abs(nums[i]);
            if(num != n+1) {
                nums[num-1] = -abs(nums[num-1]); 
            }
        }

        int i = 0;
        for(i = 0; i<n; i++) {
            if(nums[i] > 0) {
                return i+1;
            }
        }
        return n+1;


    }
};