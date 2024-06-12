class Solution {
public:
    int helper(string &s1,string &s2,int i,int j,vector<vector<int>> &dp){
        if(i==0) return j+1;
        if(j==0) return i+1;

        if(dp[i][j]!=-1) return dp[i][j];

        if(s1[i-1]==s2[j-1]) return dp[i][j]=helper(s1,s2,i-1,j-1,dp);
        else{
            int delCase =  1 + helper(s1,s2,i-1,j,dp);
            int insertCase =  1 + helper(s1,s2,i,j-1,dp);
            int replaceCase =  1 + helper(s1,s2,i-1,j-1,dp);

            return dp[i][j]=min(delCase,min(insertCase,replaceCase));
        }
    }
    
    int minDistance(string word1, string word2){
        vector<vector<int>> dp(word1.length()+1,vector<int>(word2.length()+1,-1));
        return helper(word1,word2,word1.length(),word2.length(),dp)-1;
        for(int j=0;j<word2.length();j++){
            dp[0][j]=j+1;
        }
        for(int i=0;i<word1.length();i++){
            dp[i][0]=i+1;
        }
        for(int i=1;i<word1.length();i++){
            for(int j=1;j<word2.length();j++){
                if(word1[i-1]==word2[j-1]) dp[i][j]=dp[i-1][j-1];
                else{
                    int delCase =  1 + dp[i-1][j];
                    int insertCase =  1 + dp[i][j-1];
                    int replaceCase =  1 + dp[i-1][j-1];

                    dp[i][j]=min(delCase,min(insertCase,replaceCase));
                }
            }
        }

        return dp[word1.length()][word2.length()];
    }
};
