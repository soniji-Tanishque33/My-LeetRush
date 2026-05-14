class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int gcdsofar = 0;
        for(int x : nums) {
            gcdsofar = gcd(gcdsofar, x);
            if(gcdsofar == 1) return true;
        }
        return false;
    }
};