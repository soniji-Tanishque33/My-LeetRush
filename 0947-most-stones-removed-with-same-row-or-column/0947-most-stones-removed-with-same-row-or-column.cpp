class Disjoint {
private:
    vector<int> parent;
public:
    int count;
    Disjoint(int n) {
        parent.resize(n, 0);
        for(int i = 0; i<n; i++) {
            parent[i] = i;
        }
        count = n;
    }

    int findParent(int n) {
        if(parent[n] == n) return n;
        return parent[n] = findParent(parent[n]);
    }

    void unionNodes(int u, int v) {
        int root1 = findParent(u);
        int root2 = findParent(v);

        if(root1 == root2) return;

        parent[root1] = root2;
        count--;
        return;
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();

        Disjoint dsu(n);

        for(int i = 0; i<n; i++) {
            for(int j = i+1; j<n; j++) {
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    dsu.unionNodes(i, j);
                }
            }
        }

        return n - dsu.count;




    }
};