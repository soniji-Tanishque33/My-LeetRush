class Solution {
public:
    int minSwaps(vector<int>& nums) {
        vector<int> even_index;
        vector<int> odd_index;
        for(int i = 0; i<nums.size(); i++) {
            if(nums[i]%2 == 0){
                even_index.push_back(i);
            } else {
                odd_index.push_back(i);
            }
        }

        int l1 = even_index.size();
        int l2 = odd_index.size();
        if(abs(l1-l2) > 1) return -1;

        int startwitheven = 0;
        int startwithodd = 0;
        
        for(int i = 0; i<even_index.size(); i++) {
            startwitheven += abs(even_index[i] - 2*i);
        }
        for(int i = 0; i<odd_index.size(); i++) {
            startwithodd += abs(odd_index[i] - 2*i);
        }

        int ans = INT_MAX;
        if(l1 >= l2) ans = min(ans, startwitheven);
        if(l2 >= l1) ans = min(ans, startwithodd);

        return ans;
    }
};