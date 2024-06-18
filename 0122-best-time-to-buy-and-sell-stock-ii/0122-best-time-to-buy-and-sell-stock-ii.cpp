class Solution {
public:
    int helper(vector<int> prices,int i ,int buy,vector<vector<int>> &dp){
        // base case
        if(i>=prices.size()) return 0;

        if(dp[i][buy]!=-1)return dp[i][buy];

        // recursive case
        if(buy){
            return dp[i][buy]=max((0-prices[i])+helper(prices,i+1,0,dp), //i buy
            helper(prices,i+1,1,dp)); // i dont buy
        }else{
            return dp[i][buy]=max(prices[i]+helper(prices,i+1,1,dp),//i sell
            helper(prices,i+1,0,dp)); // i don't sell
        }
    }
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
                    dp[i][buy] = max(prices[i]+dp[i+1][1],//i sell
                    dp[i+1][0]); // i don't sell
                }
            }
        }
        return dp[0][1];
    }
};