class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(s.find(part) != string::npos) {
            int start = s.find(part);
            s.erase(start, part.size());
        }
        return s;
    }
};

/*

*/