class Solution {
public:
    long long maximumCoins(vector<vector<int>>& coins, int k) {
        int n = coins.size();
        vector<int> starts(n), ends(n);
        vector<long long> prefix(n+1, 0);

        sort(coins.begin(), coins.end());

        long long ans = 0;

        // getting the prefix 
        for(int i = 0; i<n; i++) {
            starts[i] = coins[i][0];
            ends[i] = coins[i][1];
            prefix[i+1] = prefix[i] + 1LL * (coins[i][1] - coins[i][0]+1) * coins[i][2];
        }

        // taking the starts as the starting point of the final sequence
        for(int i = 0; i<n; i++) {
            int start = coins[i][0];
            int target = start+k-1;
            int j = lower_bound(ends.begin(), ends.end(), target) - ends.begin();
            long long curr = 1LL * (prefix[j] - prefix[i]);
            // taking the remaining elements of the last sequence into account
            if(j < n) curr += 1LL * max(0, target - coins[j][0] +1) * coins[j][2];

            ans = max(ans, curr);
        }

        // taking the ending in the coin interval
        for(int i =0; i<n; i++) {
            int end = coins[i][1];
            int start = end - k+1;
            int j = lower_bound(starts.begin(),starts.end(), start) - starts.begin();
            long long curr = 1LL * (prefix[i+1] - prefix[j]);
            if(j > 0) curr += 1LL * max(0, coins[j-1][1] - start +1) * coins[j-1][2];

            ans = max(ans, curr);
        }

        return ans;

    }
};