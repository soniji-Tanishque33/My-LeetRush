class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalgas = 0; 
        int totalcost = 0;

        for(int x : gas) totalgas += x;
        for(int x : cost) totalcost += x;

        if(totalcost >  totalgas) return -1;

        int start = 0;
        int curr = 0;
        for(int i = 0; i<gas.size(); i++) {
            curr += gas[i] - cost[i];

            if(curr < 0) {
                curr = 0;
                start = i+1;
            }
        }

        return start;
    }
};