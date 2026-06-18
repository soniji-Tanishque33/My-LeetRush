class Solution {
public:
    double angleClock(int hour, int minutes) {
        double ans = 0;
        double hourhand = (double)30 * hour + (double)(minutes / 2.0);
        double reverse_hourhand = hourhand - 360.0;
        double minutehand = (double)(minutes * 6);
        double reverse_minutehand = minutehand - 360.0;

        ans = min({abs(hourhand - minutehand), abs(reverse_hourhand - minutehand), abs(hourhand - reverse_minutehand), abs(reverse_hourhand - reverse_minutehand)});
        return ans;
    }
};