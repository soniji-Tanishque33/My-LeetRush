class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;

        stringstream ss(path);
        string comp;
        while(getline(ss, comp, '/')) {
            if(comp.size() == 0) continue;
            if(comp == "..") {
                if(!st.empty()) st.pop();
            } 
            else if(comp == ".") {
                continue;
            }
            else {
                st.push(comp);
            }
        }

        string ans = "";

        if(st.empty()) return "/";
        while(!st.empty()) {
            string top = st.top();
            st.pop();
            ans = "/" + top + ans;
        }
        return ans;
    }
};