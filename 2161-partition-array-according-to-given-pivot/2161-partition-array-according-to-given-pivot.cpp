class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> less_than_pivot;
        vector<int> greater_than_pivot;
        int pcount = 0;

        for(int x : nums) {
            if(x < pivot) {
                less_than_pivot.push_back(x);
            }else if(x == pivot) {
                pcount++; 
            }else {
                greater_than_pivot.push_back(x);
            }
        } 
        vector<int> ans;
        for(int x: less_than_pivot) ans.push_back(x);
        while(pcount--) ans.push_back(pivot);
        for(int x : greater_than_pivot) ans.push_back(x);

        return ans;
    }
};