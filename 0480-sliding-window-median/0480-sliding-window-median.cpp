class Solution {
public:
    priority_queue<int> left; // maxheap
    priority_queue<int, vector<int>, greater<>> right; // minheap
    unordered_map<int, int> lazy_delete;
    int left_size = 0;
    int right_size = 0;

    void prune(priority_queue<int>& left) {
        while(left.size() > 0 && lazy_delete[left.top()]) {
            lazy_delete[left.top()]--;
            left.pop();
        }
    }

    void prune(priority_queue<int, vector<int>, greater<>>& right) {
        while(right.size() > 0 && lazy_delete[right.top()]) {
            lazy_delete[right.top()]--;
            right.pop();
        }
    }
    

    void balance() {
        if(right_size >  left_size) {
            left.push(right.top());
            right.pop();
            left_size++;
            right_size--;
        }
        if(left_size > right_size+1) {
            right.push(left.top());
            left.pop();
            right_size++;
            left_size--;
        }
        prune(left);
        prune(right);
    }

    double get_median() {
        // DON'T FORGET TO PRUNE BEFORE TAKING ANSWER
        // prune(left);
        // prune(right);

        if(left_size != right_size) {
            // we will return the top of the left maxheap
            return (double) left.top();
        }
        return ((double) right.top() + (double) left.top()) / 2.0;
    }



    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        for(int i = 0; i<k; i++) {
            left.push(nums[i]);
            left_size++;
        }

        for(int i = 0; i<k/2; i++) {
            right.push(left.top());
            left.pop();
            left_size--;
            right_size++;
        }

        vector<double> res;

        res.push_back(get_median());

        for(int i = k; i<nums.size(); i++) {
            int in_num = nums[i];
            int out_num = nums[i-k];

            // removing num from the heaps
            lazy_delete[out_num]++;
            if(out_num <= left.top()) {
                // it will definately be in the left side
                left_size--;
            } else {
                // then it will be on the right
                right_size--;
            }

            balance();

            // inserting the new number
            if(in_num <= left.top()) {
                left.push(in_num);
                left_size++;
            } else {
                right.push(in_num);
                right_size++;
            }

            balance();

            res.push_back(get_median());


        }



        return res;


    }
};