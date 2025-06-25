class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        map<int, int> mpp; // number index
        for(int i = 0; i<n; i++) {
            int more =  target - nums[i];
            if(mpp.find(more) != mpp.end()) return {mpp[more], i};
            else mpp[nums[i]] = i;
        }
        return {-1,-1};
    }
};