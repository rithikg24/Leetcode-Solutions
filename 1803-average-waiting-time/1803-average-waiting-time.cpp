class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double wt=0;
        int curr=customers[0][0];
        for(auto x:customers){
            if(curr<x[0]){
                curr=x[0];
            }
            curr+=x[1];
            wt+=(curr-x[0]);
        }
        return wt/(double)customers.size();
    }
};