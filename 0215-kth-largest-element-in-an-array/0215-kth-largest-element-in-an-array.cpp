class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> maxheap;
        for(int x : nums) {
            maxheap.push(x);
        }

        k--;
        while(k--) {
            maxheap.pop();
        }
        return maxheap.top();
    }
};