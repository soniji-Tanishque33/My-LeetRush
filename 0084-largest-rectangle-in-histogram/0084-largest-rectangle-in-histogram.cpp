class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> prev_smaller;
        
        stack<int> st;

        for(int i = 0; i<heights.size(); i++) {
            while(st.size() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if(st.size() == 0) prev_smaller.push_back(-1);
            else {
                prev_smaller.push_back(st.top());
            }

            st.push(i);
        }


        st = {};
        vector<int> next_smaller(n, 0);

        for(int i = heights.size()-1; i>=0; i--) {
            while(st.size() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if(st.size() ==0) next_smaller[i] = n;
            else {
                next_smaller[i] = st.top();
            }

            st.push(i);
        }

        int ans = 0;
        for(int i = 0; i<n; i++) {
            ans = max(ans, (next_smaller[i] - prev_smaller[i]-1) * heights[i]);
        }

        return ans;




    }
};