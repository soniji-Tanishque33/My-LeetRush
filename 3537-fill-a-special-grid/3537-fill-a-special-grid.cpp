class Solution {
public:
    int val = 0;
    vector<vector<int>> grid;
    
    void solve(int r, int c, int s) {
        if(s == 1) {
            grid[r][c] = val;
            val++;
            return;
        }
        int s_ = s / 2;
        solve(r, c+s_, s_);
        solve(r+s_, c+s_, s_);
        solve(r+s_, c, s_);
        solve(r, c, s_);
    };

    vector<vector<int>> specialGrid(int n) {
        int N = 1 << n;
        grid.resize(N, vector<int>(N));
        solve(0, 0, N);
        return grid;
    }
};