class Solution {
public:
    string removeKdigits(string num, int k) {
        
        if(num.size() <= k) {
            return "0";
        }

        if(k == 0) return num;

        string res = "";

        stack<char> st;

        // st.push(num[0]);

        for(int i = 0; i<num.size(); i++) {
            while(k > 0 && !st.empty() && st.top() > num[i]) {
                --k;
                st.pop();
            }
            st.push(num[i]);

            if(st.size() == 1 && num[i] == '0') {
                st.pop();
            }
        }

        while(k && !st.empty()) {
            st.pop();
            --k;
        }

        while(!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }

        reverse(res.begin(), res.end());
        if(res.size() == 0) return "0";
        return res; 
    }
};