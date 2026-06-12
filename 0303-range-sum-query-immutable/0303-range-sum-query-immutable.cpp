class NumArray {
public:
    vector<int> segtree;
    int n;
    NumArray(vector<int>& nums) {
        n = nums.size();
        segtree.assign(4*n, 0);
        buildtree(0, 0, nums.size()-1, nums);
        // return nums;
    }

    void buildtree(int i, int l, int r, vector<int>& nums) {
        if(l == r) {
            segtree[i] = nums[l];
            return;
        }

        int mid =  (l+r) / 2;
        buildtree(2*i + 1, l, mid, nums); 
        buildtree(2*i+2, mid+1, r, nums);
        segtree[i] = segtree[2*i+1] + segtree[2*i+2];
    }
    
    int query(int start, int end, int i, int l ,int r) {
        // if outside
        if(r < start || l > end) return 0;
        // if totally inside
        if(l >= start && r <= end) {
            return segtree[i];
        }

        int mid = (l+r) / 2;
        return query(start, end, 2*i+1, l, mid) + query(start, end, 2*i+2, mid+1, r);
    }

    int sumRange(int left, int right) {
        return query(left, right, 0, 0, n-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */