class Solution {
public:
    bool isNumber(string s) {
        int index = 0;

        int decimal = 0;
        int deci_ind = 0;
        int exp = 0;
        int exp_ind = 0;
        while(index < s.size()) {
            if(s[index] == '.') {
                if(decimal == 0 && exp == 0 && (
                    (index+1 < s.size() && isdigit(s[index+1])) || 
                    (index-1 >= 0 && isdigit(s[index-1])))
                ) {
                    decimal = 1;
                    deci_ind = index;
                }
                else break;
            }
            else if(s[index] == '-' || s[index] == '+') {
                if(index == 0 && s.size() == 1) break;
                if(index != 0 && !(s[index-1] == 'e' || s[index-1] == 'E')) break;
                if(index == s.size()-1 && index > 0 && (s[index-1] == 'e' || s[index-1] == 'E')) break;
            }
            else if (s[index] == 'e' || s[index] == 'E') {
                if(exp == 1 || index == 0 || index == s.size()-1) break;
                if(!isdigit(s[index-1]) && s[index-1] != '.') break;
                exp = 1;
                exp_ind = index;

            } else {
                if(!isdigit(s[index])) break;
            }
            index++;
        }

        cout << index;

        return index == s.size();
    }
};