class Solution {
public:
// 2C1 = 2/1
// 5C3 = 5*4*3 / 3*2*1
    int ncr(int n, int r) {
        if(n == 0) return 1;

        long long ans = 1;
        for(int  i = 1; i <= r; i++) {
            ans *= (n-i+1);
            ans /= i;
        }

        return (int)ans;
    }
    vector<int> getRow(int rowIndex) {
        // check for rowIndex = 0

        
        vector<int> ans;
        for(int i = 0; i<= rowIndex; i++ ) {
            int num = ncr(rowIndex, i);
            ans.push_back(num);
        }
    
        return ans;
    }


};

//  [1] [1 1] [1 2 1]