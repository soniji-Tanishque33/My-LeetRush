class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if( k==0 ) {
            map<int, int> mp;
            for(int x : nums) {
                mp[x]++;
            }
            int cnt = 0;
            for(auto& [num, times] : mp) {
                if(times >= 2) cnt++;
            }
            return cnt;
        }

        int left = 0;
        int right = 0;
        int cnt = 0;

        set<int> s(nums.begin(), nums.end());
        vector<int> v(s.begin(), s.end());
        int n = v.size();
        
        while(right < n) {
            int diff = v[right] - v[left];
            if(diff < k) {
                right++;
            } else if(diff > k) {
                left++;
            } else {
                cnt++;
                right++;
            }
        }

        return cnt;
    }
};