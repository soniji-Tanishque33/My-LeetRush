class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> word_set(wordList.begin(), wordList.end());

        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        set<string> visited;
        visited.insert(beginWord);

        while(!q.empty()) {
            auto top = q.front();
            q.pop();
            string word = top.first;
            int step = top.second;

            if(word == endWord) return step;

            for(int i = 0; i<word.size(); i++) {
                char initial = word[i];
                for(int j = 0; j<26; j++) {
                    word[i] = 'a' + j;
                    if(word_set.find(word) != word_set.end() && visited.find(word) == visited.end()) {
                        q.push({word, step+1});
                        visited.insert(word);
                    }
                }
                word[i] = initial;
            }
        }
        return 0;
    }
};