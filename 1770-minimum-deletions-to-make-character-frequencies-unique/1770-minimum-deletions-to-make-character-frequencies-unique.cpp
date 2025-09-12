class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26, 0);
        for(char str : s) {
            freq[str - 'a']++;
        }

        int ans = 0;
        unordered_set<int> st;
        for(int i = 0; i<26; i++) {
            while(freq[i] > 0 && st.find(freq[i]) != st.end()) {
                freq[i]--;
                ans++;
            }
            st.insert(freq[i]);
        }

        return ans;
    }
};