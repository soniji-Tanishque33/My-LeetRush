class Solution {
public:
    bool checkPrime(int x) {
        if(x == 2) return true;
        for(int i = 2; i<x; i++) {
            if(x % i == 0) return false;
        }
        return true;
    }
    bool checkPrimeFrequency(vector<int>& nums) {
        vector<int> freq(101, 0);
        for(int i  =0; i<nums.size(); i++) {
            freq[nums[i]]++;
        }
        for(int i = 0; i<=100; i++) {
            if(freq[i] > 1) {
                if(checkPrime(freq[i])) return true;
            }
        }
        return false;
    }
};