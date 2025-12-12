class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        vector<vector<int>> ans;
        int m = mat.size(); // rows
        int n = mat[0].size(); // cols

        for(int i = 0; i<m; i++) {
            vector<int> temp;
            for(int j = 0; j<n; j++) {
                int answer = 0;
                for(int dr = -k; dr <=k ; dr++) {
                    for(int dc = -k; dc <= k; dc++) {
                        int r = i+dr;
                        int c = j+dc;

                        if(r >= 0 && c >= 0 && r < m && c < n) {
                            answer +=  mat[r][c];
                        }
                    }
                }
                temp.push_back(answer);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};