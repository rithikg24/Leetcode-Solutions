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
    
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.length()+1,vector<int>(word2.length()+1,-1));
        return helper(word1,word2,word1.length(),word2.length(),dp)-1;
    }
};
