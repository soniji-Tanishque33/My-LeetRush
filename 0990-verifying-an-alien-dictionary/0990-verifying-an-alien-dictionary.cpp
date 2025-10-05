class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> mp;
        int i = 0;
        for(char ch : order) {
            mp[ch] = i;
            i++;
        }

        for(string& w : words) {
            for(char& ch : w) {
                ch = mp[ch];
            }
            cout << w << endl;
        }

        return is_sorted(words.begin(), words.end());
    }
};