class Solution {
public:
    int possible_partitions(vector<int>& nums, int penalty) {
        int partitions = 1;
        int sum = 0;
        for(int i = 0; i<nums.size(); i++) {
            if(sum + nums[i] <= penalty) {
                sum += nums[i];
            } else {
                sum = nums[i];
                partitions += 1;
            }

        }
        return partitions;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = 0;
        for(int x : nums) high += x;

        while(low <= high) {
            int mid = (low + high) / 2;
            int partitions = possible_partitions(nums, mid);
            if(partitions <= k) {
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        return low;
    }
};