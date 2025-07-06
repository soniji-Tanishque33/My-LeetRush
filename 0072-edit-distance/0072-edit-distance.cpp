class Solution {
public:
    int f(int i, int j, string s1, string s2, vector<vector<int>>& dp) {
        if(i < 0) {
            return j+1;
        }
        if(j < 0) {
            return i+1;
        }
        if(dp[i][j] != -1) return dp[i][j];

        if(s1[i] == s2[j]) {
            return dp[i][j] = 0+f(i-1, j-1, s1, s2, dp);
        }

        return dp[i][j] = min({
            1+f(i-1, j, s1, s2, dp), // delete
            1+f(i, j-1, s1, s2, dp), // insert
            1+f(i-1, j-1, s1, s2, dp) // replace
        });
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        // vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        vector<int> prev(m+1, 0), curr(m+1, 0);

        for(int j = 0; j<=m; j++) prev[j] = j;

        for(int i = 1; i<=n; i++) {
            curr[0] = i;
            for(int j = 1; j<=m; j++) {
                if(word1[i-1] == word2[j-1]) {
                    curr[j] = 0+prev[j-1];
                }

                else {
                    curr[j] = min({
                        1+ prev[j], // delete
                        1+ curr[j-1], // insert
                        1+ prev[j-1] // replace
                    });
                }
            }
            prev = curr;
        }

        // for(int i = 0; i<=n; i++) {
        //     for(int j = 0; j<=m; j++) {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        return prev[m];
    }
};