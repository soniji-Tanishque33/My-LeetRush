class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if(words.size() == 0) return {};

        int wordlen = words[0].size();
        int num_words = words.size();
        int totallen = wordlen * words.size();
        
        unordered_map<string, int> freq;
        for(string w : words) freq[w]++;

        vector<int> ans;
        
        for(int i = 0; i<wordlen; i++) {
            int left = i;
            int count = 0;
            unordered_map<string, int> window;

            for(int j=i; j+wordlen <= s.size(); j += wordlen) {
                string word = s.substr(j, wordlen);

                if(freq.find(word) != freq.end()) {
                    int index = j + wordlen;
                    window[word]++;
                    count++;

                    while(window[word] > freq[word]) {
                        string left_word = s.substr(left, wordlen);
                        window[left_word]--;
                        left += wordlen;
                        count--;
                    }

                    if(count == num_words) ans.push_back(left);
                } else {
                    window.clear();
                    count = 0;
                    left = j + wordlen;
                }


            }
        }


        return ans;


    }
};  