class MedianFinder {
public:
    priority_queue<int> left; // maxheap
    priority_queue<int, vector<int>, greater<>> right; // minheap

    MedianFinder() {

    }

    void balance() {
        if(right.size() > left.size()) {
            left.push(right.top());
            right.pop();
        }

        if(left.size() > right.size()+1) {
            right.push(left.top());
            left.pop();
        }
    }
    void addNum(int num) {
        if(left.size() > 0 && num <= left.top()) {
            left.push(num);
        } else {
            right.push(num);
        }
        balance();
    }
    
    double findMedian() {
        balance();
        if(left.size() != right.size()) {
            return (double) left.top();
        }
        return ((double) left.top() + (double) right.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */