class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;

        for(int i = 0; i<s.size(); i++) {
            if(st.empty() || st.top().first != s[i]) st.push({s[i], 1});
            else {
                int prev = st.top().second;
                st.pop();
                st.push({s[i], prev+1});

                if(st.top().second == k) {
                    st.pop();
                }
            }
        }

        string ans = "";

        while(!st.empty()) {
            while(st.top().second--) {
                ans.push_back(st.top().first);
            }
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;

    }
};