class Solution {
public:
    int minimumPushes(string word) {
        int multiplier = 1;
        priority_queue<pair<int, char>, vector<pair<int, char>>> pq;
        map<char, int> mp;
        map<char, int> freq;
        for(char ch : word ) {
            freq[ch]++;
        }

        for(auto f : freq) {
            pq.push({f.second, f.first});
        }

        int counter = 8;
        while(pq.size()) {
            auto p = pq.top();
            pq.pop();
            mp[p.second] = multiplier;
            counter--;
            if(counter ==0) {
                counter = 8;
                multiplier++;
            }
        }

        int ans = 0;
        for(char ch : word) {
            ans += mp[ch];
        }

        return ans;
    }
};
/*
* we can remap the keys
number of keys =  2 - 9 = 8
 
len(s) = number of distinct characters in s
case 1 : len (s) <= 8
    ans = len(s)

case 2 : len(s) > 8
    ans = 0;
    int n = len(s)
    for the first 8 -> 1;
    for the next 8 -> 2;
    ...

     aaaaaaa
    
    - we need to map each character in the string with the number of press
    - the char that appears the most should have least number of press
    - arrange them in the decending order of the times they occur

*/