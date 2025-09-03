class Solution {
public:
    int calculate(string s) {
        stack<pair<int, int>> st;
        int sum = 0;
        int sign = 1;
        int ans = 0;

        for(int i = 0; i<s.size(); i++) {
           
            if(isdigit(s[i])) {
                int num = 0;
                while(i < s.size() && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                i--;
                ans += num * sign;
                sign = 1;
            }
            else if(s[i] == '(') {
                st.push({ans, sign});
                ans = 0;
                sign = 1;
            } else if(s[i] == ')') {
                auto p = st.top();
                st.pop();
                ans = p.first + p.second * ans;
            } else if ( s[i] == '-') {
                sign = -1 * sign;
            }
            
        }

        return ans;
    }
};