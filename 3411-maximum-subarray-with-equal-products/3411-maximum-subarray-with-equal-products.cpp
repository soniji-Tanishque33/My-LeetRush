class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i<n; i++) {
            long long hcf = (long long)nums[i];
            long long _lcm = (long long)nums[i];
            long long prod = 1;
            long long maxlcm = 1e12;
            for(int  j = i; j<n; j++) {

                hcf = gcd(hcf, (long long)nums[j]);
                _lcm = lcm(_lcm, (long long)nums[j]);
                prod *= (long long)nums[j];
                if(prod > maxlcm) break;
                

                if(prod == _lcm * hcf) ans = max(ans, j-i+1);
            }
        }


        return ans;
    }
};