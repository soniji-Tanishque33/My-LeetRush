class Solution {
public:
    bool checker(string s) {
        if(s.size() == 0) return false;
        string org= s;
        string rev = s;
        reverse(rev.begin(), rev.end());
        if(rev == org) return true;
        return false;
    }
    int method1(string s) {
        int ans = 0;
        for(int i = 0; i<s.size(); i++) {
            for(int j = i; j<s.size(); j++) {
                if(checker(s.substr(i,j-i+1))) ans++;
            }
        }
        return ans;
    }

    int counter_2(string s, int left, int right) {
        int count = 0;
        while(left >= 0 && right < s.size() && s[left] == s[right]) {
            --left;
            ++right;
            ++count;
        }
        return count;
    }
    int method2(string s) {
        int ans = 0;
        for(int i = 0; i<s.size(); i++) {
            int even = counter_2(s, i, i+1);
            int odd = counter_2(s, i , i);
            ans += even+odd;
        }

        return ans;
    }
    int countSubstrings(string s) {
        return method2(s);
    }
};