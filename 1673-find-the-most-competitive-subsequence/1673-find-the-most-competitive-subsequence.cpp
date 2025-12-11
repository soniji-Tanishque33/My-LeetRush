class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n = nums.size();

        stack<int> st;

        for(int i = 0; i<n; i++) {

            while(st.size() > 0 && nums[i] < st.top() && (n-i-1 >= k-st.size())) {
                st.pop();
            }
            
            if(st.size() < k) st.push(nums[i]);
        }

        vector<int> ans;
        while(st.size()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};