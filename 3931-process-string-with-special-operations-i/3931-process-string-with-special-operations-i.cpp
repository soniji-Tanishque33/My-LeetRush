class Solution {
public:
    string processStr(string s) {
        if(s.size() == 0) return "";
        string res = "";

        for(char x : s) {
            if(x == '*') {
                int len = res.size();
                if(len == 0) continue;
                res = res.substr(0, len-1);
            } else if(x ==  '#') {
                res = res + res;
            } else if(x == '%') {
                reverse(res.begin(), res.end());
            } else {
                res += x;
            }
        }
        return res;
        
    }
};