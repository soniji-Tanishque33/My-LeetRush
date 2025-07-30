class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> dir = {
            // top
            {0, 1},
            // bottom
            {0, -1},
            // left
            {-1, 0},
            // right
            {1, 0},
            // top left
            {-1, -1},
            // top right
            {-1, 1},
            // bottom left
            {1, -1},
            // bottom right
            {1, 1}
        };

        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                int count = 0;
                for(auto d : dir) {
                    int x = i + d[0];
                    int y = j + d[1];

                    if(x >= 0 && y >= 0 && x < m && y < n && (board[x][y] == 1  || board[x][y] == 2)) {
                        count++;
                    }
                }

                if(board[i][j] == 1 && (count < 2 || count > 3)) {
                    board[i][j] = 2;  // alive to be dead
                }

                else if(board[i][j] == 0 && count == 3) {
                    board[i][j] = 3;
                }
            }
        }

        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(board[i][j] == 2) {
                    board[i][j] = 0;
                }
                else if(board[i][j] == 3) {
                    board[i][j] = 1;
                }
            }
        } 
    }
};