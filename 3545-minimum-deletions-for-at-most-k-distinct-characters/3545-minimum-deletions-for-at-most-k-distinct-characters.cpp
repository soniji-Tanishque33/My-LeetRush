class Solution {
public:
    int minDeletion(string s, int k) {
        map<char,int> mp;
        for(char ch : s) {
            mp[ch]++;
        }

        if(mp.size() <= k) return 0;
        set<pair<int, char>> st;
        for(auto it: mp) {
            char ch = it.first;
            int count = it.second;
            st.insert({count, ch});
        }
        int ans = 0;
        while(st.size() > k) {
            ans += st.begin()->first;
            st.erase(st.begin());
        }

        return ans;
    }
};