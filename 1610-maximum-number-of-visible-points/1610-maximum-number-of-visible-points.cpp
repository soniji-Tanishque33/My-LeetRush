class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
       /**
       points = [[x, y], []]
        angle = represents the field in deg
        loacketion= [given x, given y] = given postiono that does not change
        iintiitlly east facing ->
        cannot mofef but rotaote

        let d is the amount of degreees i need to rotate in counter clockwise diren
        field of view = [d-angle/2, d+angle/2]
       */ 
        double pi = acos(-1.0);
        int ans = 0;
        vector<double> angle_points;

        for(auto& p: points) {
            if(p[0] == location[0] && p[1] == location[1]) {
                ans++;
            } else {
                int dx = p[1] - location[1];
                int dy = p[0] - location[0];

                double radian_angle = atan2(dy, dx);
                double angle = radian_angle * 180 / pi;

                angle_points.push_back(angle);
                // angle_points.push_back(angle+360);
            }
        }

        sort(angle_points.begin(), angle_points.end());
        int n = angle_points.size();
        for(int i  = 0; i<n; i++) {
            angle_points.push_back(angle_points[i]+360);
        }

        int count = 0;
        int start = 0;
        for(int i = 0; i<angle_points.size(); i++) {
            if(angle_points[i] - angle_points[start] > angle) {
                start++;
            }
            count = max(count, i-start+1);
        }

        ans += count;
        return ans;

    }
};