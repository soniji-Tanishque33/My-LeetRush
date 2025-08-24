class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int leftcount = 0;
        int rightcount = 0 ;

        stack<char> st;

        for(int i = 0; i<s.size(); i++) {
            if(s[i] == '(') {
                leftcount++;
            } else if(s[i] == ')') {
                rightcount++;
            }
            if(rightcount >  leftcount) {
                rightcount--;
                continue;
            } else {
                st.push(s[i]);
            }
        }

        string ans;
        while(!st.empty()) {
            char curr = st.top();
            st.pop();
            if(leftcount > rightcount && curr == '(') {
                leftcount--;
            } else {
                ans += curr;
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};