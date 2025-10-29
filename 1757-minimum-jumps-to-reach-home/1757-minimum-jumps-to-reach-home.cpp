class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        int ans = 0;
        
        queue<tuple<int, int, int>> q;
        q.push({0, 0, false});
        bool opt = true;
        unordered_set<int> forbidden_set(forbidden.begin(), forbidden.end());
        unordered_set<string> visited;
        visited.insert("0_0");
        int limit = 6000;


        while(!q.empty()) {
            auto top = q.front();
            int curr = get<0>(top);
            int jump = get<1>(top);
            int back = get<2>(top);
            q.pop();

            if(curr < 0) continue;
            if(curr == x) return jump;
            
            int forward_next = curr + a;
            string visit_forward = to_string(forward_next) + "_0";
            if(forward_next < limit && forbidden_set.find(forward_next) == forbidden_set.end() && visited.find(visit_forward) == visited.end()) {
                q.push({forward_next, jump+1, true});
                visited.insert(visit_forward);
            }

            int back_next = curr-b;
            string visited_back = to_string(back_next) + "_1";
            if(back && back_next >= 0 && forbidden_set.find(back_next) == forbidden_set.end() && visited.find(visited_back) == visited.end()) {
                q.push({back_next, jump+1, false});
                visited.insert(visited_back);
            }

        }


        return -1;
    }
};