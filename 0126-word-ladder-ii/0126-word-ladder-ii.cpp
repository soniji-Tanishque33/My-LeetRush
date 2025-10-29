class Solution {
public: 
    unordered_map<string, int> mpp; 
    string b;
    vector<vector<string>> ans;
    void dfs(string word, vector<string>& temp) {
        if(word == b) {
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            reverse(temp.begin(), temp.end());
            return ;
        }
        int step = mpp[word];
        for(int i = 0; i<word.size(); i++) {
            char initial = word[i];
            for(char ch = 'a'; ch <= 'z'; ch++) {
                word[i] = ch;
                if(mpp.find(word) != mpp.end() && mpp[word]+1 == step) {
                    temp.push_back(word);
                    dfs(word, temp);
                    temp.pop_back();
                }
            }
            word[i] = initial;
        }

    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
      
        unordered_set<string> word_set(wordList.begin(), wordList.end());
    
        mpp[beginWord] = 1;
        word_set.erase(beginWord);

        queue<string> q;
        q.push(beginWord);
        b = beginWord;
        word_set.erase(beginWord);
        while(!q.empty()) {
            string word = q.front();
            q.pop();
            int step = mpp[word];
            if(word == endWord) break; 
            
            for (int i = 0; i<word.size(); i++) {
                char initial = word[i];
                for(char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;
                    if(word_set.find(word) != word_set.end()) {
                        q.push(word);
                        word_set.erase(word);
                        mpp[word] = step+1;
                    }
                }
                word[i] = initial;

            }
        }

        if(mpp.find(endWord) != mpp.end()) {
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord, seq);
        }
        


        return ans;
    }
};