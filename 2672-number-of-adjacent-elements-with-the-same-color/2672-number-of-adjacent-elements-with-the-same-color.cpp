class Solution {
public:
    int f(vector<int>& arr, int prev, int ind, int color) {
        int ans = prev;
        if(arr[ind] == 0) {
            // it was not colored;
            arr[ind] = color;
            if(ind-1 >= 0 && arr[ind-1] == arr[ind]) {
                ans += 1;
            }
            if(ind+1 < arr.size() && arr[ind] == arr[ind+1]) {
                ans += 1;
            }
        } else {
            // it was already colored;

            // check if the neighbors had the same color
            // if yes decrement ans
            if(ind-1 >= 0 && arr[ind-1] == arr[ind]) {
                ans -= 1;
            }
            if(ind+1 < arr.size() && arr[ind] == arr[ind+1]) {
                ans -= 1;
            }
            // change it to the desired color
            // check the neighbor again to increment it
            arr[ind] = color;
            if(ind-1 >= 0 && arr[ind-1] == arr[ind]) {
                ans += 1;
            }
            if(ind+1 < arr.size() && arr[ind] == arr[ind+1]) {
                ans += 1;
            }

        }
        return ans;
    }
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        vector<int> arr(n, 0);
        int prev = 0;
        vector<int> answer;
        for(auto query: queries) {
            int index = query[0];
            int color = query[1];
            int ans = f(arr, prev, index, color);
            prev = ans;
            answer.push_back(ans);
        }

        return answer;

    }
};