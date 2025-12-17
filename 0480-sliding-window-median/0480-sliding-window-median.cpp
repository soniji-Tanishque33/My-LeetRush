class Solution {
public:
    priority_queue<int> left; // maxheap
    priority_queue<int, vector<int>, greater<>> right; // minHeap;
    unordered_map<int, int> lazy_delete; // index : count;
    int left_size = 0;
    int right_size = 0;


    void prune_left(priority_queue<int>& left) {
        while(!left.empty() && lazy_delete[left.top()] > 0) {
            lazy_delete[left.top()]--;
            left.pop();
        }
    }

    void prune_right(priority_queue<int, vector<int>, greater<>>& right) {
        while(!right.empty() && lazy_delete[right.top()] > 0) {
            lazy_delete[right.top()]--;
            right.pop();
        }
    }


    

    double get_median() {
        // always prune before
        prune_left(left);
        prune_right(right);

        if(left_size != right_size) {
            return (double)left.top();
        }
        double ans = ((double)left.top() + (double)right.top()) / 2.0;
        return ans;
    }

    void balance() {
        if(left_size > right_size + 1) {
            right.push(left.top());
            left.pop();
            right_size++;
            left_size--;
        }
        if(right_size > left_size) {
            left.push(right.top());
            right.pop();
            left_size++;
            right_size--;
        }

        prune_left(left);
        prune_right(right);
    }

    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        
        vector<double> res;

        for(int i = 0; i<k; i++) {
            left.push(nums[i]);
            left_size++;
        }

        for(int i = 0; i<k/2; i++) {
            right.push(left.top());
            left.pop();
            right_size++;
            left_size--;
        }

        double ans = get_median();
        res.push_back(ans);


        for(int i = k; i<nums.size(); i++) {
            int out_num = nums[i-k];
            int in_num = nums[i];

            if(left_size > 0 && out_num <= left.top()) {
                lazy_delete[out_num]++;
                left_size--;
            } else {
                lazy_delete[out_num]++;
                right_size--;
            }

            balance();

            if(left.empty() || in_num < left.top()) {
                left.push(in_num); left_size++;
            }
            else {
                right.push(in_num);
                right_size++;
            }

            balance();


            res.push_back(get_median());

        }



        return res;

        
    }
};