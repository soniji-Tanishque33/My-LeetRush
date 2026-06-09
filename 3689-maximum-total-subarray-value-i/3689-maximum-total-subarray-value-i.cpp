class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
       long long max_value = LONG_MIN; 
       long long min_value = LONG_MAX;

       for(int x : nums) {
            if(x > max_value) max_value = x;
            if(x < min_value) min_value = x;
       }

       cout << max_value << " " << min_value << endl;

       return 1LL * k * (max_value - min_value);
    }
};