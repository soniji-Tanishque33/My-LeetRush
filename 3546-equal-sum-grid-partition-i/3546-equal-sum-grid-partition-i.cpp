class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        vector<int> vertical;
        vector<int> horizontal;
        int m = grid.size();
        int n = grid[0].size();
        long long horizontal_sum = 0;
        long long vertical_sum = 0;

        for(int i = 0; i<m; i++) {
            long long sum = 0;
            for(int j= 0; j<n; j++) {
                sum += grid[i][j];
            }
            horizontal.push_back(sum);
            horizontal_sum += sum;
        }

        for(int i = 0; i<n; i++) {
            long long sum = 0;
            for(int j = 0; j<m; j++) {
                sum += grid[j][i];
            }
            vertical.push_back(sum);
            vertical_sum += sum;
        }

        long long target_h = -1;
        long long target_v = -1;
        if(horizontal_sum %2 == 0)  target_h = horizontal_sum / 2;
        if(vertical_sum %2 == 0)  target_v = vertical_sum / 2;

        if(target_h == -1 && target_v == -1) return false;

        long long rolling_sum = 0;
        for(int i = 0; i<vertical.size(); i++) {
            rolling_sum += vertical[i];
            if(rolling_sum == target_v) return true;
            if(rolling_sum > target_v) break;
        }

        rolling_sum = 0;
        for(int i = 0; i<horizontal.size(); i++) {
            rolling_sum += horizontal[i];
            if(rolling_sum == target_h) return true;
            if(rolling_sum > target_h) break;
        }

        return false;



    }
};