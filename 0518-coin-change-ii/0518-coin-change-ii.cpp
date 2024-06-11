class Solution {
public:    
    int change(int amount, vector<int>& coins) {
        vector<int> prev(amount+1,0);
        vector<int> curr(amount+1,0);

        for(int amt=0;amt<amount+1;amt++){
            if(amt%coins[0]==0) prev[amt]=1;
        }

        for(int i=1;i<coins.size();i++){
            for(int amt=0;amt<amount+1;amt++){
                int notTake = prev[amt];
                int take=0;
                if(coins[i]<=amt) take=curr[amt-coins[i]];
                curr[amt]=notTake+take;
            }
            prev=curr;
        }

        return prev[amount];
    }
};