class Solution {
public:
    string convert(string s, int numRows) {
        map<int, vector<char>> mp;
        int d = 1, idx = 0;

        for(int i = 0; i<s.size(); i++) {
            mp[idx].push_back(s[i]);
            if(idx == 0) {
                d = 1;
            }
            else if(idx == numRows-1) {
                d = -1;
            }
            idx += d;
        }

        string ans = "";
        for(auto& [idx, vec] : mp) {
            // cout << idx << " ";
            for(char ch : vec) {
                // cout << ch << " ";
                ans+=ch;
            }
            // cout << endl;
        }

        return ans;
    }
};