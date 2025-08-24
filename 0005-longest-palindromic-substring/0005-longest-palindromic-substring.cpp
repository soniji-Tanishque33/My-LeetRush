class Solution {
public:
    pair<int, int> f(string s, int st, int en) {
        int l = st;
        int r = en;
        while(l >= 0 && r < s.size() && s[l] == s[r]) {
            l--;
            r++;
        }

        return {l+1, r-l-1};
    }

    string longestPalindrome(string s) {
        int n = s.size();

        int start = 0;
        int len = 0;
        for(int i = 0; i<n; i++) {
            int l = i;
            int r = i;
            
            pair<int, int> p = f(s, l, r);
            if(p.second > len) {
                start = p.first;
                len = p.second;
            }

            l = i;
            r = i+1;
            p = f(s, l, r);
            if(p.second > len) {
                start = p.first;
                len = p.second;
            }

        }

        return s.substr(start, len);
    }
};