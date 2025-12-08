class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> mp;

        for(char ch : s) {
            mp[ch]++;
        }

        priority_queue<pair<int, char>, vector<pair<int, char>>> q;

        for(auto it: mp) {
            q.push({it.second, it.first});
        }

        pair<int, char> prev = {0, '#'};

        string ans = "";

        while(!q.empty()) {

            auto curr = q.top(); q.pop();

            ans += curr.second;

            if(prev.first > 0) {
                q.push(prev);
            }

            curr.first--;
            prev = curr;

        }


        if(ans.size() != s.size()) return "";
        return ans;
    }
};