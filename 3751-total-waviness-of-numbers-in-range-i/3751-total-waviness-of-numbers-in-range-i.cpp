class Solution {
public:
    int calculate(int n) {
        string s = to_string(n);
        if(s.size() < 3) return 0;

        int ans = 0;
        for(int i = 1; i<s.size()-1; i++){
            int prev = s[i-1] - '0';
            int curr = s[i] - '0';
            int next = s[i+1] - '0';
            if(curr > next && curr >  prev) ans++;
            else if(curr < next && curr < prev) ans++;
        }

        return ans;
    }
    int totalWaviness(int num1, int num2) {
        int ans = 0;
        for(int i = num1; i<= num2; i++) {
            ans += calculate(i);
        }

        return ans;
    }
};

/*
waviness
peak a_i-1 < a_i > a_i+1
*/