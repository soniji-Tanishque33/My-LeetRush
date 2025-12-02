class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;

        for(string s : tokens) {
            if(isdigit(s[s.size()-1])) {
                st.push(s);
            } else {
                string first = st.top(); st.pop();
                string second = st.top(); st.pop();
                if(s == "+") {
                    int sum = stoi(first) + stoi(second);
                    st.push(to_string(sum));
                }
                else if(s == "-") {
                    int diff = stoi(second) - stoi(first);
                    st.push(to_string(diff));
                }
                else if(s == "*") {
                    int prod = stoi(first) * stoi(second);
                    st.push(to_string(prod));
                }
                else if(s == "/") {
                    int divi = stoi(second) / stoi(first);
                    st.push(to_string(divi));
                }
            }
        }

        if(st.empty()) return 0;
        return stoi(st.top());
    }
};