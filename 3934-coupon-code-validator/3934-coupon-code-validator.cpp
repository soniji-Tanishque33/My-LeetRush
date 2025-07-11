class Solution {
public:
    bool check(string str) {
        for(char s : str) {
            if(!(s <= 'z' && s >= 'a') && !(s <= 'Z' && s >= 'A') && !(s >= '0' && s <= '9') && !(s == '_')) return false;
        }
        return true;
    }
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        map<string, vector<string>> mp;
        int n = code.size();

        for(int i = 0; i<n; i++) {
            if(isActive[i]) {
                mp[businessLine[i]].push_back(code[i]);
            }
        }

        vector<string> ans;

        for(auto& [line, coupons] : mp) {
            if(!(line == "grocery" || line == "pharmacy" || line == "restaurant" || line == "electronics")) continue;
            sort(coupons.begin(), coupons.end());
            for(string& coupon : coupons) {
                if(coupon.size() > 0 && check(coupon)) {
                    ans.push_back(coupon);
                }
            }
        }
        return ans;
    }
};