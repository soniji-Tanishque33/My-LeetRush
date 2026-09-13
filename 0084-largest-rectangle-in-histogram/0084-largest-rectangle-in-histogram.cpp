class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        
        vector<int> next_smaller(n, n);
        vector<int> prev_smaller(n, -1);

        stack<int> st;

        for(int i = 0; i<n; i++) {
            while(st.size() > 0 && heights[st.top()] >= heights[i]) st.pop();

            if(st.size() != 0) prev_smaller[i] = st.top();

            st.push(i);
        }


        st = {};

        for(int i = n-1; i>=0 ; i--) {
            while(st.size() > 0 && heights[st.top()] >= heights[i]) st.pop();

            if(st.size() != 0) next_smaller[i] = st.top();

            st.push(i);
        }


        int ans = 0;

        for(int i = 0; i<n; i++) {
            ans = max(ans, heights[i] * (next_smaller[i] - prev_smaller[i] - 1));
        }
        return ans;
    }
};