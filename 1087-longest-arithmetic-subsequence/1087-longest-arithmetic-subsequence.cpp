class Solution {
public:
    
    int longestArithSeqLength(vector<int>& nums) {
       
       // edge case
       // if all numbers are same

       vector<unordered_map<int, int>> v(nums.size());

        int ans = 1;
       for(int i = 0; i<nums.size(); i++) {
            for(int j = 0; j < i; j++) {
                int diff = nums[i] - nums[j] + 510;
                int len = 2;
                if(v[j].count(diff)) {
                    len = 1+v[j][diff];
                }

                v[i][diff] = len;
                ans = max(ans, len);
            }
       }

       return ans;



       
        
    }
};