class Solution {
public:
    string minWindow(string s, string t) {
       if(s.size() < t.size()) return "";

        int start = 0;
        vector<int> window = {0, INT_MAX};

        unordered_map<char, int> freq;
        int targetRemaining = 0;
        for(char ch : t) {
           freq[ch]++;
           targetRemaining++; 
        }

        for(int endindex = 0; endindex < s.size(); endindex++) {
            if(freq.find(s[endindex]) != freq.end() && freq[s[endindex]] > 0) {
                targetRemaining--;
            }
            freq[s[endindex]]--;

            if(targetRemaining == 0) {

                while(true) {
                    if(freq.find(s[start]) != freq.end() && freq[s[start]] == 0) {
                        break;
                    }
                    freq[s[start]]++;
                    start++;
                }

                if(window[1] - window[0] > endindex - start) {
                    window[0] = start;
                    window[1] = endindex;
                }

                freq[s[start]]++;
                start++;
                targetRemaining++;
            }
        } 

        if(window[1] != INT_MAX) {
            return s.substr(window[0], window[1] - window[0] +1);
        }

        return "";

    }
};