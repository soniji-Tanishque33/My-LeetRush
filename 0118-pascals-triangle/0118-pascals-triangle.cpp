class Solution {
public:
    void f(int rows, vector<vector<int>>& ans) {

        for(int i = 2; i < rows; i++) {
            vector<int> temp;
            int sizeofprev = ans[i-1].size(); // 2
            for(int j = 0; j<=i; j++) {
                int next = 0;
                if(j-1 >= 0 ) {
                    next += ans[i-1][j-1];
                } 
                if( j < sizeofprev) {
                    next += ans[i-1][j];
                }
                temp.push_back(next);
            }
            ans.push_back(temp);
        }

    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        if(numRows <= 0) return ans;
        ans.push_back({1});
        if(numRows == 1) return ans;

        ans.push_back({1, 1});
        if(numRows == 2) return ans;

        f(numRows, ans); 

        return ans;

        
    }
};