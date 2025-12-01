class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;

        int index = nums2.size()-1;
        // vector<int> next_gre;
        unordered_map<int, int> mp;
        while(index >= 0) {
            if(st.empty()) {
                // next_gre.push_back(-1);
                st.push(index);
                mp[nums2[index]] = -1;
                index--;
                continue;
            }

            while(st.size() > 0 && nums2[st.top()] < nums2[index]) {
                st.pop();
            }
            if(!st.empty()) {
                mp[nums2[index]] = nums2[st.top()];
                // next_gre.push_back(nums2[st.top()]);
            } else {
                mp[nums2[index]] = -1;
                // next_gre.push_back(-1);
            }
            st.push(index);
            index--;
        }
        // reverse(next_gre.begin(), next_gre.end());

        vector<int> ans;
        for(int i  : nums1) {
            ans.push_back(mp[i]);
        }
        return ans;


    }
};