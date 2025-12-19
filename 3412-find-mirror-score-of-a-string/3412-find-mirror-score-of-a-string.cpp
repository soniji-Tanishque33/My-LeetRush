class Solution {
public:
    long long calculateScore(string s) {
        int n = s.size();
        vector<bool> marked(n, false);
        long long ans = 0;
        map<char, char> mp;
        for(int i = 0; i<26; i++) {
            mp['a' + i] = 'z' - i;
        }

        map<char, set<int>> str;

        for(int i = 0; i<s.size(); i++) {
            char ch = s[i];
            char mirror = mp[ch];

            if(str.find(mirror) == str.end()) {
                str[ch].insert(i);
            } else {
                int j = *prev(str[mirror].end());
                ans += (i-j);
                str[mirror].erase(j);
                if(str[mirror].size() == 0) str.erase(mirror);
            }
        }

        return ans;
    }
};

// a + z = 27
// b + y = 27