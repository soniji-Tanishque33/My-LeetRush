class Solution {
public:
    using ll = long long;
    long long maxArea(vector<vector<int>>& coords) {
        map<int, set<int>> xMap, yMap;
        set<int> allX, allY;

        for(auto& coor : coords) {
            xMap[coor[0]].insert(coor[1]);
            yMap[coor[1]].insert(coor[0]);

            allX.insert(coor[0]);
            allY.insert(coor[1]);
        }

        ll ans = LLONG_MIN;

        for(auto &[x, ySet] : xMap) {
            if(ySet.size() < 2) continue;

            int minY = *ySet.begin();
            int maxY = *ySet.rbegin();
            int base = abs(maxY - minY);

            int minX = *allX.begin();
            int maxX = *allX.rbegin();
            
            if(maxX != x) ans = max(ans, base * 1LL * abs(x - maxX));
            if(minX != x) ans = max(ans, base * 1LL * abs(x - minX));
        }

        for(auto &[y, xSet] : yMap) {
            if(xSet.size() < 2) continue;

            int minX = *xSet.begin();
            int maxX = *xSet.rbegin();
            int base = abs(maxX - minX);

            int minY = *allY.begin();
            int maxY = *allY.rbegin();

            if(minY != y) ans = max(ans, base * 1LL * abs(y-minY));
            if(maxY != y) ans = max(ans, base * 1LL * abs(y-maxY));
        }

        return ans == LLONG_MIN ? -1 :  ans;
    }
};