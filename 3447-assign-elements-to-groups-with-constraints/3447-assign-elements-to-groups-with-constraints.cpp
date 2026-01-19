class Solution {
public:
    vector<int> assignElements(vector<int>& groups, vector<int>& elements) {
        const int max = 1e5+5;

        vector<int> entry(max, -1);
        vector<int> assigned(max, -1);

        for(int i = 0; i<elements.size(); i++) {
            if(entry[elements[i]] == -1) {
                entry[elements[i]] = i;
            }
        }

        for(int i = 0; i<max; i++) {

            if(entry[i] != -1) {
                int curr_index = entry[i];
                for(int j = i; j<max; j+=i) {
                    if(assigned[j] == -1 || curr_index < assigned[j]) {
                        assigned[j] = curr_index;
                    }
                }
            }
        }

        vector<int> res;

        for(int g : groups) {
            res.push_back(assigned[g]);
        }

        return res;
    }
};