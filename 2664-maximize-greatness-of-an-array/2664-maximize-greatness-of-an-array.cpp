class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        // NHI CHALA KHUD SE TRY KARNE PAR BC!!
        // vector<pair<int, int>> v;
        // for(int i = 0; i<nums.size(); i++) {
        //     v.push_back({nums[i], i});
        // }

        // if(!is_sorted(nums.begin(), nums.end())) sort(v.begin(), v.end());
        // int ans = 0;
        // for(int i = 0; i<nums.size(); i++) {
        //     int x = nums[i];
        //     int idx = -1;
        //     pair<int, int> lookingfor = {x, -1};
        //     auto it = upper_bound(v.begin(), v.end(), lookingfor);
        //     if(it == v.begin()) continue;
        //     ans++;
        //     v.erase(it-1);
        // }
        // return ans;

        // ABB COPY KAR RAHA DUSRO KA

        int res = 0;
        sort(nums.begin(), nums.end());

        for(int x : nums) {
            if(x > nums[res]) res++;
        }
        return res;

    }
};