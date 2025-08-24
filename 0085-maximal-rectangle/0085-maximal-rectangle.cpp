class Solution {
public:
    int largest_rectangle(vector<int>& row) {
        int n = row.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);

        stack<int> st;

        for(int i = 0; i<n; i++) {
            while(!st.empty() && row[st.top()] >= row[i]) st.pop();
            left[i] = !st.empty() ? st.top() : -1;
            st.push(i);
        }

        st = {};

        for(int j = n-1; j>=0; j--) {
            while(!st.empty() && row[st.top()] >= row[j]) st.pop();
            right[j] = !st.empty() ? st.top() : n;
            st.push(j);
        }

        int maxarea = 0;
        for(int i = 0; i < row.size(); i++) {
            maxarea = max(maxarea, row[i] * (right[i] - left[i] - 1));
        }

        return maxarea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> height(m, vector<int>(n, -1));

        for(int i = 0; i<n; i++) {
            int sum = 0;
            for(int j = 0; j<m; j++) {
                sum += matrix[j][i] - '0';
                if(matrix[j][i] == '0') sum = 0;
                height[j][i] = sum;
            }
        }

        int ans = 0;
        for(auto& row : height) {
            ans = max(ans, largest_rectangle(row));
        }

        return ans;
    }
};