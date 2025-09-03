class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hangle = (30) * hour + (0.5) * minutes;
        double mangle = (6) * minutes;

        return min(abs(360 - abs(hangle - mangle)), abs(hangle - mangle));
    }
};