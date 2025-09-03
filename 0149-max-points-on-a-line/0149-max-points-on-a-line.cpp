class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        
        int n = points.size();
        if(n <= 2) return n;

        int global_max=0;

        for(int i = 0; i<points.size(); i++) {
            map<pair<int, int>, int> slopes;

            for(int j = i+1; j<points.size(); j++) {
                
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                if(dx < 0) {
                    dx = -1*dx;
                    dy = -1*dy;
                }

                if(dx == 0) {
                    slopes[{1, 0}]++;
                } else {
                    int _gcd = gcd(dy, dx);
                    dx = dx/_gcd;
                    dy = dy/_gcd;

                    slopes[{dy, dx}]++;
                }
            }
            int local_max = 0;
            if(!slopes.empty()) {
                for(auto [key, val] : slopes) {
                    local_max = max(local_max, val);
                }
            }

            global_max = max(global_max, local_max+1);
        }

        return global_max;

    }


};