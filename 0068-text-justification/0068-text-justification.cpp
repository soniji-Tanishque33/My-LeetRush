    class Solution {
    public:
        string f(vector<string>& words, int maxwidth, int start, int end, bool lastline) {
            string ans = "";
            int total_len = 0;
            int num_words = end-start+1;
            int spaces_in_between = num_words-1;
            for(int x = start; x <= end; x++) {
                total_len += words[x].size();
            }
            
            if(lastline || num_words == 1) {
                for(int i = start; i<=end; i++) {
                    ans += words[i];
                    if(i != end) ans += " ";
                }

                while(ans.size() < maxwidth) ans += " ";
                return ans;
            }

            int spaces_left = maxwidth - total_len;
            int even_spaces = spaces_left / spaces_in_between;
            int extra = spaces_left % spaces_in_between;

            for(int i = start; i< end; i++ ) {
                ans += words[i];
                ans.append(even_spaces, ' ');
                if(extra > 0) {
                    ans += " ";
                    extra--;
                }
            }
            ans += words[end];

            return ans;


        }
        vector<string> fullJustify(vector<string>& words, int maxWidth) {
            vector<string> ans;
            
            bool lastline = false;
            int i = 0;
            while(i < words.size()) {
                int currlen = 0;
                int j = i;
                
                while(j < words.size() && currlen + words[j].size() + (j-i) <= maxWidth)  {
                    currlen += words[j].size();
                    j++;
                }

                if(j == words.size()) lastline= true;
                ans.push_back(f(words, maxWidth, i, j-1, lastline));
                i = j;
            }

            return ans;
        }
    };