class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int time = 0;
        vector<int> freq(26, 0);

        for(char ch : tasks) {
            freq[ch - 'A']++;
        }

        priority_queue<int> maxHeap;
        for(int i = 0; i<26; i++) {
            if(freq[i] > 0) maxHeap.push(freq[i]);
        }

        while(!maxHeap.empty()) {
            int cycles = n+1;
            int taskCount = 0;
            vector<int> store;

            while(cycles && !maxHeap.empty()) {
                int top = maxHeap.top();
                maxHeap.pop();

               if(top > 1) store.push_back(top-1);
                cycles--;
                taskCount++;
            }

            for(int x : store) maxHeap.push(x);

            if(maxHeap.empty()) {
                time += taskCount;
            } else {
                time += n+1;
            }
        }

        return time;
    }
};




