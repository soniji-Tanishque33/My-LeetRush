class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long, vector<long>, greater<>> pq;

        unordered_set<long> seen;

        long currugly = 1;
        pq.push(1);
        vector<int> primefactors = {2, 3, 5};

        for(int i = 0; i<n; i++) {
            currugly = pq.top();
            pq.pop();

            for(int prime : primefactors) {
                long next = currugly * prime;
                if(seen.find(next) ==  seen.end()) {
                    seen.insert(next);
                    pq.push(next);
                }
            }
        }

        return currugly;
    }
};