/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int ans = 0;

    void dfs(unordered_map<int, vector<int>>& id_sub, unordered_map<int, int>& id_imp, int id) {
        
        ans += id_imp[id];

        for(int sub : id_sub[id]) {
            dfs(id_sub, id_imp, sub);
        }
    }

    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, vector<int>> id_sub;
        unordered_map<int, int> id_imp;

        for(auto& e: employees) {
            id_sub[e->id] = e->subordinates;
            id_imp[e->id] = e->importance;
        }   

        dfs(id_sub, id_imp, id);
        return ans;
        // queue<int> q;
        
        // q.push(id);
        // int ans = 0;
        // while(!q.empty()) {
        //     int top = q.front(); q.pop();
        //     ans += id_imp[top];
        //     for(int sub : id_sub[top]) {
        //         q.push(sub);
        //     }
        // }

        // return ans;

    }
};