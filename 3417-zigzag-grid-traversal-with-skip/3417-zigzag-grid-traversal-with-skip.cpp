class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int row = 0;
        vector<int> ans;
        int  counter = 0;

        while(row < m) {
            for(int i = 0; i<n; i++) {
                if(counter % 2 == 0) ans.push_back(grid[row][i]);
                counter++;
            }
            row++;
            if(row < m) {
                for(int i = n-1; i>= 0; i--) {
                    if(counter % 2 == 0) ans.push_back(grid[row][i]);
                    counter++;
                }
                row++;
            }
        }

        return ans;
    }
};