class Disjoint {
public:
    vector<int> parent;
    Disjoint(int n ){
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

        parent[parentu]= parentv;
        return ;
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        Disjoint dsu(n);
        int extra = 0;
        
        for(auto conn: connections) {
            int u = conn[0];
            int v = conn[1];

            if(dsu.findParent(u) == dsu.findParent(v)) extra++;
            else dsu.unionNodes(u, v);
        }

        int comp = 0;
        for(int i = 0; i<n; i++) {
            if(dsu.findParent(i) == i) comp++;
        }

        int ans = comp-1;

        if(extra >= ans) return ans;
        return -1;
    }
};