class Solution {
public:

    unordered_map<int, string> mp;
    int counter = 0;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        counter++;
        mp[counter] = longUrl;
        return to_string(counter);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return mp[stoi(shortUrl)];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));