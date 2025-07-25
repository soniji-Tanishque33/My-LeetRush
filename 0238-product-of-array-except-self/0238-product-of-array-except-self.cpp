class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> left_pdt(n, 1);
        vector<int> right_pdt(n, 1);
        
        // populate the left pdt
        for(int i = 1; i<n; i++) {
            left_pdt[i] = left_pdt[i-1] * nums[i-1];
        }
        // populate the right pdt
        for(int i = n-2; i>=0; i--) {
            right_pdt[i] = right_pdt[i+1] * nums[i+1];
        }

        vector<int> ans;
        for(int i = 0; i<n; i++) {
            ans.push_back(left_pdt[i]*right_pdt[i]);
        }
        return ans;
    }
};