class Solution {
public:
    bool f(int index, string s, unordered_set<string>& st, vector<int>& dp) {
        // base case
        if(index == s.size()) {
            return true;
        }
        if(dp[index] != -1) return dp[index];

        // recurrsion
        for(int j = index+1; j<=s.size(); j++) {
            string str = s.substr(index, j-index);
            if(st.find(str) != st.end() && f(j, s, st, dp)) {
                return dp[index] = true;
            }
        }

        return dp[index] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());

        vector<int> dp(s.size()+1, 0);
        dp[s.size()] = 1;
        for(int index = s.size()-1; index >= 0; index-- ) {
            for(int j = index+1; j<=s.size(); j++) {
                string str = s.substr(index, j-index);
                if(st.find(str) != st.end() && dp[j]) {
                    dp[index] = 1;
                    break;
                }
            }
        }
        return dp[0];
    }
};