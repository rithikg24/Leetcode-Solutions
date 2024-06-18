class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size()+1,vector<vector<int>>(2,vector<int>(k+1,-1)));
        // return helper(prices,0,1,2,dp);

        for(int buy=0;buy<2;buy++){
            for(int j=0;j<=k;j++){
                dp[prices.size()][buy][j]=0;
            }
        }
        for(int i=0;i<prices.size()+1;i++){
            for(int buy=0;buy<2;buy++){
                dp[i][buy][0]=0;
            }
        }

        for(int i=prices.size()-1;i>=0;i--){
            for(int buy=0;buy<2;buy++){
                for(int j=1;j<=k;j++){
                    if(buy){
                        dp[i][buy][j]=max((0-prices[i])+dp[i+1][0][j], //i buy
                        dp[i+1][1][j]); // i dont buy
                    }else{
                        dp[i][buy][j]=max(prices[i]+dp[i+1][1][j-1],//i sell
                        dp[i+1][0][j]); // i don't sell
                    }
                }
            }
        }

        return dp[0][1][k];
    }
};