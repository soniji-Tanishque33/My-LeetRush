class Solution {
public:
    char processStr(string s, long long k) {
        
        long long len = 0;
        for(int i = 0; i<s.size(); i++) {
            if(islower(s[i])) len++;
            else if(s[i] == '*' && len > 0) len--;
            else if(s[i] == '#') len *= 2;
        }

        if(k >= len) return '.';

        for(int i = s.size()-1; i >= 0; i--) {
            char c = s[i];
            if(islower(s[i])) {
                if(k == len - 1) return c;
                len--;
            } else if(s[i] == '*') {
                len++;
            } else if(s[i] == '#') {
                len = len/2;
                if(k >= len) k = k-len;
            } else if(s[i] == '%') {
                k = len - (k+1);
            }
        }
        return '.';
        
    }
};
// a#bc%    k = 2
// aabc => cbaa => 4 - (2 + 1) = 1

// aab => baa
// k = 1 => 3 - (1+1) = 1

// ab#  k = 2
//      k - len = 0