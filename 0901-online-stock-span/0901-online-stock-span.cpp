class StockSpanner {
public:
    stack<pair<int, int>> st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        if(st.empty()) {
            st.push({price, 1});
            return 1;
        }
        int added = 0;
        while(st.size() > 0 && st.top().first <= price) {
            added += st.top().second;
            st.pop();
        }
        if(added > 0) {
            st.push({price, added+1});
            return added+1;
        }
        st.push({price, 1});
        return 1;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */