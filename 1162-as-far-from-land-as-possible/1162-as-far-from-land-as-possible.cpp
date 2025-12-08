class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        // this is a multisource bfs.. 
        // you need to start the bfs from all the land cells(the reverse process.. generally we start it from the water cells)

        int n = grid.size();
        queue<pair<int, int>> q;

        vector<vector<int>> visited = grid;

        for(int i = 0; i<grid.size(); i++) {
            for(int j = 0; j<grid.size(); j++) {
                if(grid[i][j] == 1) {
                    q.push({i, j});
                }
            }
        }

        int distance = -1;
        if(q.size() == 0 || q.size() == n*n) {
            // this means either there are no land cells or no water cells
            return -1;
        }  

        // top bottom left right
        vector<pair<int, int>> dd = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

        while(!q.empty()) {
            int size = q.size();

            while(size--) {
                pair<int, int> p = q.front();q.pop();
                int x = p.first;
                int y = p.second;
                for(int i = 0; i<4; i++) {
                    int nx = x + dd[i].first;
                    int ny = y + dd[i].second;
                    if(nx >= 0 && ny >= 0 && nx < n && ny < n && visited[nx][ny] == 0) {
                        visited[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
            }
            distance++;
        }

        return distance;
    }
};