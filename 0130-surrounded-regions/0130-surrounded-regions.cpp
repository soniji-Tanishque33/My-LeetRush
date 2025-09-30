class Solution {
public:
    void dfs(int x, int y, vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        if(x < 0 || x >= m || y < 0 || y >= n || board[x][y] !='O') return ;

        board[x][y] = 'A';
        dfs(x+1, y, board);
        dfs(x, y+1, board);
        dfs(x-1, y, board);
        dfs(x, y-1, board);

    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        for(int j=0; j<n; j++) {
            if(board[0][j] == 'O') {
                dfs(0, j, board);
            }
            if(board[m-1][j] == 'O') {
                dfs(m-1, j, board);
            } 
        }

        for(int i = 1; i<m-1; i++) {
            if(board[i][0] == 'O') {
                dfs(i, 0, board);
            }
            if(board[i][n-1] == 'O'){
                dfs(i, n-1, board);
            }
        }

        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(board[i][j] == 'O') board[i][j] = 'X';
                else if(board[i][j] == 'A') board[i][j] = 'O';
            }
        }
    }
};