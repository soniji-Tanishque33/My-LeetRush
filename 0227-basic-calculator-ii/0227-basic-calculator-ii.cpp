class Solution {
public:
    int calculate(string s) {
        int currNum = 0;
        int n = s.size();
        char op = '+';

        stack<int> st;

        for(int i= 0; i<s.size(); i++) {
            char currchar = s[i];
            if(isdigit(currchar)) {
                currNum = currNum * 10 + (currchar-'0');
            }
            if((!isdigit(s[i]) && !isspace(s[i])) || i == n - 1) {
                if(op == '+') {
                    st.push(currNum);
                }
                else if (op == '-') {
                    st.push(-1*currNum);
                }
                else if(op == '*') {
                    int top = st.top();
                    st.pop();
                    st.push(top * currNum);
                }
                else if (op == '/') {
                    int top = st.top();
                    st.pop();
                    st.push(top / currNum);
                }

                currNum = 0;
                op = s[i];
            }
        }

        int res = 0;
        while(!st.empty()) {
            int top = st.top();
            res += top;
            st.pop();
        }

        return res;
    }
};