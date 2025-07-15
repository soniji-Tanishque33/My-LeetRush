class Solution {
public:
    vector<string> partitionString(string s) {
        int index = 0;
        unordered_map<string, int> mp;
        vector<string> ans;
        
        string l = "";
        for(int i = 0; i<s.size(); i++ ) {
            l += s[i];
            if(mp.find(l) == mp.end()) {
                mp[l] = i;
                ans.push_back(l);
                l = "";
            }
        }


        return ans;
    }
};