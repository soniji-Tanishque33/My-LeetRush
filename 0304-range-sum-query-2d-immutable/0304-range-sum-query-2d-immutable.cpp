class NumMatrix {
public:
    vector<vector<int>> prefix_sum;
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        prefix_sum.assign(m, vector<int>(n, 0));
        prefix_sum[0][0] = matrix[0][0];

        for(int i = 1; i<m; i++) {
            prefix_sum[i][0] = prefix_sum[i-1][0] + matrix[i][0];
        }
        for(int j = 1; j<n; j++) {
            prefix_sum[0][j] = prefix_sum[0][j-1] + matrix[0][j];
        }

        for(int i = 1; i<m; i++) {
            for(int j = 1; j<n; j++) {
                prefix_sum[i][j] = matrix[i][j] + prefix_sum[i-1][j] + prefix_sum[i][j-1] - prefix_sum[i-1][j-1];
            }
        }


    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = prefix_sum[row2][col2];
        int del = 0;
        if(col1 > 0) del += prefix_sum[row2][col1-1];
        if(row1 > 0) del += prefix_sum[row1-1][col2];
        if(col1 != 0 && row1 != 0) del -= prefix_sum[row1-1][col1-1];

        return ans-del;

    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */