class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return 0;
        vector<int> arr(n);
        arr[n-1] = nums[n-1];

        for(int i = n-2; i>=0; i--) {
            arr[i] = arr[i+1] + nums[i];
        }

        int ans = 0;
        for(int i = 0; i<n-1; i++) {
            int avg = arr[i+1] / (n-(i+1));
            if(nums[i] > avg) ans++;
        }
        return ans;

    }
};