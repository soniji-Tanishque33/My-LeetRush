class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int i = 0;
        string ans = "";
        for(i = 0; i<s.size(); i++) {
            string word = "";
            while(s[i] != ' ' && i < s.size()) {
                word += s[i];
                i++;
            }
            reverse(word.begin(), word.end());
            if(word.size() > 0) ans += " " + word;
        }

        return ans.substr(1);
    }
};