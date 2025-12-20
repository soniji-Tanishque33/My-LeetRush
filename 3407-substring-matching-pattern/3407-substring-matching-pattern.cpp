class Solution {
public:
    bool hasMatch(string s, string p) {
        string first = "", second = "";
        bool fl = true;

        for(char ch : p) {
            if(ch == '*') {
                fl = false;
                continue;
            }
            if(fl == true) {
                first += ch;
            } else {
                second += ch;
            }
        } 

        int second_max;
        int fpos;
        string scopy = s;
        string replacement = "";
        for(int i = 0; i<second.size(); i++) replacement += "*";
        if(first.size() > 0) {
            fpos = s.find(first);
            if(fpos == string::npos) return false;
            scopy.erase(fpos, first.size());
        }
        
        if(second.size() > 0) {
            int spos = scopy.find(second);
            if(spos == string::npos) return false;
            string temp = scopy;
            while(temp.size() > 0 && temp.find(second) != string::npos) {
                spos = temp.find(second);
                second_max = spos;
                cout << spos << endl;
                temp.replace(spos, second.size(), replacement);
            }
        }

        if(first.size() > 0 && second.size() > 0 && fpos > second_max) return false;


        return true;
    }
};