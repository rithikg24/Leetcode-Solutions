class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minNum=prices[0];
        int profit=0;
        for(int i=1;i<prices.size();i++){
            int diff=prices[i]-minNum;
            profit=max(profit,diff);
            minNum=min(minNum,prices[i]);
        }
        return profit;
    }
};