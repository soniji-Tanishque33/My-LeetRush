class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> ans;
        ans = image;
        int n = image.size();
        int m = image[0].size();
        queue<pair<int, int>> q;
        int initial = image[sr][sc];
        q.push({sr, sc});
        // top right bottom left
        int dx[] = {0, +1, 0, -1};
        int dy[] = {+1, 0, -1, 0};

        while(!q.empty()) {
            auto p = q.front();
            q.pop();
            int row = p.first;
            int col = p.second;
            ans[row][col] = color; 
            for(int i = 0; i<4; i++) {
                int nrow = row - dx[i];
                int ncol = col - dy[i];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == initial && ans[nrow][ncol] != color) {
                    q.push({nrow, ncol});
                }
            }

        }

        return ans;
    }
};