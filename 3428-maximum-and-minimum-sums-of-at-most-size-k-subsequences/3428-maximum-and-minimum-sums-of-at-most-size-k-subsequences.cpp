const int Q = 1e9+7;
const int N = 1e5;
const int M = 1e9;

class Solution {
private:
    int add(int a, int b) {
        long long x = a+b;
        while(x >= Q) x -= Q;
        return x;
    }
    int pdt(int a, int b) {
        long long x = 1LL * a * b  % Q;
        return x;
    }

public:
    int minMaxSums(vector<int>& nums, int k) {
        int n = nums.size();
        int c[n+1][k+1];

        c[0][0] = 1;
        c[1][0] = 1;
        c[1][1] = 1;

        for(int i =2; i<=n; i++) {
            c[i][0] = 1;
            if(i <= k) c[i][i] = 1;
            for(int l = 1; l<=k && l < i; l++) {
                c[i][l] = add(c[i-1][l], c[i-1][l-1]);
            }
        }

        int ans = 0;
        sort(nums.begin(), nums.end());

        for(int i = 0; i<n; i++) {

            int s = nums[i];
            int p = 0;
            for(int l=0; l < k && l <= n-i-1 ; l++) {
                p = add(p, c[n-i-1][l]);
            }

            ans = add(ans, pdt(s, p));
        }

        reverse(nums.begin(), nums.end());

        for(int i = 0; i<n; i++) {
            int s = nums[i];
            int p = 0;
            for(int l = 0; l < k && l <= n-i-1; l++) {
                p = add(p, c[n-i-1][l]);
            }

            ans = add(ans, pdt(s, p));
        }

        return ans;

    }
};