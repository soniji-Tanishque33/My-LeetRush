class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        vector<long long> ans;

        stack<long long> st;
        int n = nums.size();

        for(int i = 0; i<n; i++) {
            if(st.size() == 0) { st.push(nums[i]); }
            else {
                if(st.top() == nums[i]) {
                    long long x = nums[i];
                    
                    while(st.size() && st.top() == x) {
                        st.pop();
                        x = 2 * x;
                    }
                    st.push(x);
                } else {
                    st.push(nums[i]);
                }
            }
        }

        while(st.size()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};