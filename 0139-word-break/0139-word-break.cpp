class Solution {
public:
    bool f(int i, string s, unordered_set<string>& all, vector<int>& dp) {
        
        if(i == s.size()) return true;
        if(dp[i] != -1) return dp[i];
        
        for(int j = i+1; j<=s.size(); j++) {
            string str = s.substr(i, j-i);
            if(all.find(str) != all.end() && f(j, s, all, dp)){
                return dp[i] =  true;
            } 
        }

        return dp[i] = false;

    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = wordDict.size();
        unordered_set<string> all(wordDict.begin(), wordDict.end());
        vector<int> dp(s.size(), -1);
        return f(0, s, all, dp);
        
    }
};