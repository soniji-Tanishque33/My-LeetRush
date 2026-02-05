class Solution {
public:
    int n;
    vector<int> arr;
    int memo[100005][2][2];


    int f(int index, int expect_up, int skipped) {
        if(index >= n-1) return 0;
        if(memo[index][expect_up][skipped] != -1) return memo[index][expect_up][skipped];

        int res = 0;
        if(expect_up) {
            if(arr[index+1] > arr[index]) {
                res = max(res, 1+f(index+1, 0, skipped));
            }
        } else {
            if(arr[index+1] < arr[index]) {
                res = max(res, 1+f(index+1, 1, skipped));
            }
        }

        if(skipped == 0 && index+2 < n) {
            if(expect_up) {
                if(arr[index+2] > arr[index]){
                    res = max(res, 1+f(index+2, 0, 1));
                }
            } else {
                if(arr[index+2] < arr[index]) {
                    res = max(res, 1+f(index+2, 1, 1));
                }
            }
        }

        return memo[index][expect_up][skipped] = res;
    }


    int longestAlternating(vector<int>& nums) {
        n = nums.size();
        arr = nums;
        
        for(int i = 0; i<n+3; i++) {
            for(int j = 0; j<2; j++) {
                for(int k = 0; k<2; k++) {
                    memo[i][j][k] = -1;

                }
            }
        }

        int maxlen = 1;

        for(int i=0; i<n; i++) {
            int start_up = 1+f(i, 1, 0);
            int start_down = 1+f(i, 0, 0);

            maxlen = max({maxlen, start_up, start_down});
        } 

        return maxlen;      
    }
};