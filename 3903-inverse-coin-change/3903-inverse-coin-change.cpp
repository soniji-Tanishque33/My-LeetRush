class Solution {
public:
    vector<int> findCoins(vector<int>& numWays) {
        
        int n = numWays.size();
        vector<int> ways(n+1, 0);
        ways[0] = 1;
        vector<int> coins;

        for(int a = 1; a<=n; a++) {
            int have = ways[a];
            int want = numWays[a-1];
            int diff = want - have;

            if(have > want) return {};
            if(have == want) continue;
            if(diff != 1) return {};
            coins.push_back(a);

            for(int j = a; j<=n; j++) {
                ways[j] += ways[j-a];
            }

        }

        return coins;
        
    }
};