class Disjoint {
private:
    vector<int> parent;
public:
    Disjoint(int n) {
        parent.resize(n);
        for(int i = 0; i<n; i++) {
            parent[i] = i;
        }
    }

    int findParent(int node) {
        if(node == parent[node]) return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionNodes(int u, int v) {
        int parentu = findParent(u);
        int parentv = findParent(v);
        if(parentu == parentv) return;

        parent[parentu] = parentv;
        return;
    }
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {

        Disjoint dsu(27);

        for(auto eq: equations) {
            if(eq[1] == '=') {
                int x = eq[0] - 'a';
                int y = eq[3] - 'a';
                dsu.unionNodes(x, y);
            }
        }
        

        for(auto eq: equations) {
            if(eq[1] == '!') {
                int x = eq[0] - 'a';
                int y = eq[3] - 'a';

                if(dsu.findParent(x) == dsu.findParent(y)) return false;

            }
        }


        return true;
    }

};