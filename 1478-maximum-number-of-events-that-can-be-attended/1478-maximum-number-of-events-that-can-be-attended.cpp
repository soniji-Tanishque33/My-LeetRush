class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        int n = events.size();
        
        priority_queue<int, vector<int>, greater<int>> minHeap;

        int count = 0;
        int day = events[0][0];
        int index = 0;

        while(!minHeap.empty() || index < n) {
            if(minHeap.empty()) {
                day = events[index][0];
            }
            while(index < n && day == events[index][0]) {
                minHeap.push(events[index][1]);
                index++;
            }
            minHeap.pop();
            count++;
            day++;

            while(!minHeap.empty() && minHeap.top() < day) {
                minHeap.pop();
            }
        }
        
        return count;

    }
};