class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        long long ans = 0;
        int MOD = 1e9 + 7;
        int n = arr.size();
        vector<int> left(n), right(n);

        stack<int> st;

        // lesser element to the left
        for(int i = 0; i<n; i++) {
            while(!st.empty() && arr[st.top()] > arr[i]) st.pop();
            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        // next lesser element
        for(int i = n-1; i >= 0; i--) {
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }        

        for(int i = 0; i<n; i++) {
            long long l = i - left[i];
            long long r = right[i] - i;
            ans = (ans + arr[i] * l * r) % MOD;
        }

        return ans;
    }
};