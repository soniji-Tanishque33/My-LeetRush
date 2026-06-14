class Solution {
public:
    long long maxSum(vector<int>& nums, int k) {
        int n = nums.size();
        multiset<int> candidates, others;
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        long long ans = LONG_MIN;

        for(int i = 0; i<n; i++) {
            candidates.clear();
            others.clear();

            for(int i = 0; i<max(0, n-k); i++) {
                others.insert(sorted[i]);
            }

            for(int i =max(0, n-k); i<n; i++) {
                candidates.insert(sorted[i]);
            }

            long long currsum = 0;

            for(int j = i; j<n;j++) {
                if(others.size() > 0) {

                    int x = nums[j];
                    auto it = others.find(x);
                    int val;
                    if(it != others.end()) {
                        val = x;
                        others.erase(it);
                    } else {
                        auto it_largest_other = prev(others.end());
                        val = *it_largest_other;
                        others.erase(it_largest_other);
                    }
                    candidates.insert(val);
                }

                auto largest = prev(candidates.end());
                currsum += *largest;
                candidates.erase(largest);

                ans = max(ans, currsum);
            }

            
        }

        return ans;
    }
};