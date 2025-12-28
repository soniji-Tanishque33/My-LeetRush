class Solution {
public:
    set<int> st = {2, 5, 6, 9};
    set<int> counted;
    bool f(int x) {

        bool found_different = false;

        while(x > 0) {
            int d=x%10;
            if(d == 3 || d == 4 || d == 7) return false;
            if(d == 2 || d == 5 || d == 6 || d == 9) found_different = true;
            x /= 10;
        }
        return found_different;
    }
    int rotatedDigits(int n) {
        int ans = 0;
        for(int i = 1; i<=n; i++) {
            if(f(i)) {
                ans++;
            }
        }


        return ans;
       
    }
};