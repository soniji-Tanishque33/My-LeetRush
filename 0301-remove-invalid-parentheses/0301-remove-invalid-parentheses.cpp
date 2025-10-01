class Solution {
public:
    void f(string s, int left, int right, vector<char> para, vector<string>& ans) {
        int counter = 0;
        while(right < s.size()) {
            if(s[right] == para[0]) {
                counter++;
            } 
            else if(s[right] == para[1]) {
                counter--;
            }
            if(counter < 0) break;
            right++;
        }

        if(counter < 0) {
            // => ( << ) => para[0] < para[1]
            while(left <= right) {
                // skip duplicate cases
                if(s[left] != para[1] || (left > 0 && s[left] == s[left-1])) {
                    left++;
                    continue;
                }
                s.erase(left, 1);
                f(s, left, right, para, ans);
                s.insert(s.begin()+left, para[1]);
                left++;
            }
        }
        else if(counter > 0) {
            reverse(s.begin(), s.end());
            f(s, 0, 0, {')', '('}, ans);
        }
        else {
            ans.push_back(para[0] == '(' ? s : string(s.rbegin(), s.rend()));
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        f(s, 0, 0, {'(', ')'}, ans);
        return ans;
    }
};