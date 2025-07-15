class Solution {
public:
    int longest_prefix(string s1, string s2) {
        int ans = 0;
        for(int i = 0; i<min(s1.size(), s2.size()); i++) {
            if(s1[i] != s2[i]) return i;
        }
        return min(s1.size(), s2.size());
    }
    vector<int> longestCommonPrefix(vector<string>& words) {
        int n = words.size();
        vector<int> lcp;
        vector<int> ans(n, 0);
        if(n <= 1) return ans;

        for(int i = 0; i<n-1; i++) {
            lcp.push_back(longest_prefix(words[i], words[i+1]));
        }

        vector<int> prefix(n-1, 0), suffix(n-1, 0);

        prefix[0] = lcp[0];
        for(int i = 1; i<n-1; i++) {
            prefix[i] = max(prefix[i-1], lcp[i]);
        }

        suffix[n-2] = lcp[n-2];
        for(int i = n-3; i>=0; i--) {
            suffix[i] = max(lcp[i], suffix[i+1]);
        }


        for(int i = 0; i<n; i++) {
            int best = 0;

            if(i >= 2) best = max(best, prefix[i-2]);
            if(i+1 <= n-2) best = max(best, suffix[i+1]);
            if(i > 0 && i < n-1) best = max(best, longest_prefix(words[i-1], words[i+1]));
            ans[i] = best;
        }

        return ans;

    }
};