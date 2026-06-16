class Solution {
public:
    string processStr(string s) {
        string ans = "";

        for(char ch : s) {
            if(ch == '*') {
                if(ans.size() > 0) ans.pop_back();
            }
            else if(ch == '#') {
                string temp =  ans;
                ans = ans + temp;
            }
            else if(ch == '%') {
                reverse(ans.begin(), ans.end());
            }
            else if(ch - 'a' >= 0 && ch - 'a' < 26) {
                ans.push_back(ch);
            }
        }

        return ans;
    }
};