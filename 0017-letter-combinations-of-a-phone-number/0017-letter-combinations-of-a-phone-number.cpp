class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<int, vector<char>> mp = {
            {2, {'a', 'b', 'c'}},
            {3, {'d', 'e', 'f'}},
            {4, {'g', 'h', 'i'}},
            {5, {'j', 'k', 'l'}},
            {6, {'m', 'n', 'o'}},
            {7, {'p', 'q', 'r', 's'}},
            {8, {'t', 'u', 'v'}},
            {9, {'w', 'x', 'y', 'z'}}
        };

        vector<string> ans;

        for(char s : digits) {
            int num = s - '0';
            if(ans.size() == 0) {
                for(char characters : mp[num]) {
                    ans.push_back(string(1, characters));
                }
            } else {
                int n = ans.size();
                for(int i = 0; i<n; i++) {
                    string str  = *ans.begin();
                    ans.erase(ans.begin());
                    for(char ch : mp[num]) {
                        ans.push_back(str + ch);
                    }
                }
            }
        }

        return ans;
    }
};