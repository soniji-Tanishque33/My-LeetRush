class Solution {
public:
    double distance(vector<int>& p1, vector<int>& p2) {
        return (p1[0] - p2[0])*(p1[0] - p2[0]) + (p1[1] - p2[1])*(p1[1] - p2[1]);
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<double> disvec;
        disvec.push_back(distance(p1, p2));
        disvec.push_back(distance(p1, p3));
        disvec.push_back(distance(p1, p4));
        disvec.push_back(distance(p2, p3));
        disvec.push_back(distance(p2, p4));
        disvec.push_back(distance(p3, p4));

        int n = disvec.size();
        sort(disvec.begin(), disvec.end());
        for (double x : disvec) cout << x << " ";
        cout << endl;
        for(int i = 1; i<4; i++) {
            if(disvec[i-1] != disvec[i]) return false;
        }
        cout << 1;
        if(disvec[n-2] != disvec[n-1]) return false;
        cout << 2;

        if(disvec[n-1] != 2 * disvec[0]) return false;
        cout <<3;
        return disvec[0] > 0;

    }
};