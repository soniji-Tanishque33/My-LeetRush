class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        queue<int> q;
        for(int i = 0; i<nums.size(); i++) {
            if(nums[i] != 0) q.push(i);
        }
        int index = 0;
        while(index < nums.size()) {
            if(nums[index]== 0) {
                int min_greater_index = -1;
                while(min_greater_index < index) {
                    if(!q.empty()){
                     min_greater_index = q.front(); q.pop();
                    }   
                    else{
                        return;
                    }
                }
                if(min_greater_index == -1) return;
                swap(nums[index], nums[min_greater_index]);
            }
            index++;
        }
    }
};