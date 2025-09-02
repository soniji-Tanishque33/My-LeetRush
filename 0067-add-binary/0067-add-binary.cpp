class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int carry = 0;

        int left = a.size()-1;
        int right = b.size()-1;

        while(left >= 0 || right >= 0 || carry) {
            char num1 = '0';
            if(left >= 0) num1 = a[left];
            char num2 = '0';
            if(right >= 0) num2 = b[right];

            if(num1 == '1' && num2 == '1') {
                if(carry == 1) {
                    res += '1';
                } else {
                    res += '0';
                    carry = 1;
                }
            }
            else if((num1 == '0' && num2 == '1') || (num1 == '1' && num2 == '0')) {
                if(carry == 1) {
                    res += '0';
                    carry = 1;
                } else {
                    res += '1';
                }
            } 
            else if (num1 == '0' && num2 == '0') {
                if(carry == 1) {
                    res += '1';
                    carry = 0;
                } else {
                    res += '0';
                }
            }
            left--;
            right--;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};