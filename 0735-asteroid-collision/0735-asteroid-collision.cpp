class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        list<int> st;

        int n = asteroids.size();
        for(int  i= 0; i<n; i++) {
            if(asteroids[i] > 0) {
                st.push_back(asteroids[i]);
            }
            else {
                while(st.size() > 0 && st.back() > 0 && st.back() < abs(asteroids[i])) {
                    st.pop_back();
                }
                if(st.size() > 0 && st.back() == abs(asteroids[i])) {
                    st.pop_back();
                } else if(st.size() == 0 || st.back() < 0) {
                    st.push_back(asteroids[i]);
                }
            }
        }

        return vector<int>(st.begin(), st.end());
    }
};