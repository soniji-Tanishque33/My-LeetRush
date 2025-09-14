class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> dp(n, 1);
        // if(n >= 2) {
        //     if(ratings[0] > ratings[1]) {
        //         ++dp[0];
        //     }
        // }

        for(int i = 1; i<n; i++) {
            if(ratings[i] > ratings[i-1]) {
                dp[i] = dp[i-1] + 1;
            }
        }

        for(int i = n-2; i>=0; i--) {
            if(ratings[i] > ratings[i+1]) {
                dp[i] = max(dp[i], dp[i+1]+1);
            }
        }


        // if(n-2 >= 0) {
        //     if(ratings[n-1] > ratings[n-2]) {
        //         dp[n-1] = dp[n-2] + 1;
        //     }
        // }
        
        int sum = 0;
        for (int x : dp) {
            cout << x << " ";
            sum += x;
        }
        return sum;

    }
};