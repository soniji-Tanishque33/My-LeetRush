class Solution {
public:
    int f(vector<int>& w, int cap) {
        int days = 1;
        int load = 0;
        for(int i = 0; i<w.size(); i++) {
            if(load + w[i] > cap) {
                days++;
                load= w[i];
            } else {
                load += w[i];
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int min_capacity = *max_element(weights.begin(), weights.end());
        int max_capacity = 0;
        for(int x : weights) max_capacity += x;

        
        // for(int i = min_capacity; i<= max_capacity; i++) {
        //     int req_days = f(weights, i);
        //     if(req_days <= days) return i;
        // } 

        // binary search optimization
        int low = min_capacity;
        int high = max_capacity;
        int ans = -1;
        while(low <= high) {
            int mid = (low + high) / 2;
            int req_days = f(weights, mid);
            if(req_days <= days) {
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        return low;
    }
};