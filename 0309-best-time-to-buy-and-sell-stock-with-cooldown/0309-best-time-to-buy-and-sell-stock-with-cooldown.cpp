class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size()+1,vector<int>(2,-1));

        for(int i=0;i<2;i++){
            dp[prices.size()][i]=0;
        }

        for(int i=prices.size()-1;i>=0;i--){
            for(int buy=0;buy<2;buy++){
                if(buy){
                    dp[i][buy] = max((0-prices[i])+dp[i+1][0], //i buy
                    dp[i+1][1]); // i dont buy
                }else{
                    if(i+2>=prices.size()+1){
                        dp[i][buy] = max(prices[i],//i sell
                    dp[i+1][0]);
                    }else{
                        dp[i][buy] = max(prices[i]+dp[i+2][1],//i sell
                    dp[i+1][0]); // i don't sell
                    }
                }
            }
        }
        return dp[0][1];
    }
};