class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();

        queue<pair<int, int>> q;
        q.push({1, 0});

        vector<vector<bool>> visited(n, vector<bool>(n, false));

        while(!q.empty()) {
            auto top = q.front();
            q.pop();
            int sum = top.first;
            int level = top.second;
            if(sum == n*n) return level;

            for(int d = 1; d <= 6; d++) {
                int next = sum + d;
                if(next > n*n) break;
                int row = (n-1) - (next-1)/n;
                int col = (n-row) % 2 ==  1 ?  (next-1) % n : n-1-(next-1) % n;

                if(visited[row][col]) continue;
                visited[row][col] = true;

                if(board[row][col] != -1) {
                    q.push({board[row][col], level+1});
                } else {
                    q.push({next, level+1});
                }
            }
        }

        return -1;
    }
};


                // [5, 0] => 1 = 6 * (6-5) - (6-1 - 0) = 6 - 5 = 1
                // [5, 1] => 2 =  6 * (6-5) - (6-1 - 1) = 6 - 4 = 2
                // [5, 2] => 3
                // [5, 3] => 4
                // [5, 4] => 5
                // [5, 5] => 6 => 6*(5-5) + 5
                // [4, 5] => 7 => 6 * (6-4) + 5 = 12 - 5
                // [4 0] => 6 * (5-4) + 0 = 12
                // [3 0] => (9) + 0
                // [4, 0] => 12 => 1 + 11
                // [0 0] => 36 => 6 * 6
                // [11, 6] => [11%5 = 1, 6 - 6/5 = 1]
                // [2, 2] [4, 3]
                // [7, 7] => [2, 1]