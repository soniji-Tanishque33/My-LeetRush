class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int unique = 0;
        set<int> st;
        for(int i=0; i<nums.size(); i++) {
            if(st.find(nums[i]) == st.end()) {
                nums[unique] = nums[i];
                unique++;
                st.insert(nums[i]);
            }
        }

        return unique;
    }
};