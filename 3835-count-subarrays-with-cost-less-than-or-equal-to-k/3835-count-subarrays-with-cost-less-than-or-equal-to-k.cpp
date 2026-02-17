class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        deque<int> maxq, minq;
        long long res = 0;

        int l = 0;  
        int n = nums.size();
        for(int r = 0; r < n; r++) {
            while(maxq.size() && nums[maxq.back()] <= nums[r]) {
                maxq.pop_back();
            }
            maxq.push_back(r);
            while(minq.size() && nums[minq.back()] >= nums[r]) {
                minq.pop_back();
            }
            minq.push_back(r);


            while(l <= r && 1LL * (r-l+1) * (long long) (nums[maxq.front()] - nums[minq.front()]) > k) {
                if(maxq.size() && maxq.front() == l) {
                    maxq.pop_front();
                }
                if(minq.size() && minq.front() == l) {
                    minq.pop_front();
                }
                l++;
            }

            res += (r-l+1);
        } 
        return res;
    }
};