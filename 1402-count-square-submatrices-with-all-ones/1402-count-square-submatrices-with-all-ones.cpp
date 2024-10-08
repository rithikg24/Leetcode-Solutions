class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size(),0));
        int res=0;

        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==1){ 
                    dp[i][j]=1;
                    if(i==0 || j==0) res++;
                }
            }
        }
        for(int i=1;i<matrix.size();i++){
            for(int j=1;j<matrix[0].size();j++){
                if(matrix[i][j]==1){
                    matrix[i][j]+=min(matrix[i-1][j],min(matrix[i][j-1],matrix[i-1][j-1]));
                    res+=matrix[i][j];
                }
            }
        }

        return res;
    }
};