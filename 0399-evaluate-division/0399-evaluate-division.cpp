class Solution {
public:
    void dfs(unordered_map<string, unordered_map<string, double>>& mp, string node, string& dest, set<string>& visited, double& ans, double temp) {
        if(visited.find(node) != visited.end()) return;

        visited.insert(node);

        if(node == dest) {
            ans = temp;
            return;
        }

        for(auto ne : mp[node]) {
            dfs(mp, ne.first, dest, visited, ans, temp * ne.second);
        }



    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> mp;

        for(int i = 0; i<equations.size(); i++) {
            string dividend = equations[i][0];
            string divisor = equations[i][1];

            mp[dividend][divisor] = values[i];
            mp[divisor][dividend] = 1.0 / values[i];
        }

        vector<double> ans;

        for(auto& q : queries) {
            string dividend = q[0];
            string divisor = q[1];
            set<string> visited;
            double res = -1.0;
            if(mp.find(dividend) == mp.end() || mp.find(divisor) == mp.end()) {
               res = -1.0;
            } else {
                dfs(mp, dividend, divisor, visited, res, 1.0);
            }

            ans.push_back(res);
        }

        return ans;
    }
};