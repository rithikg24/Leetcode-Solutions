class Solution {
public:
    int helper(string a,string b,int m,int n){
        if(m==0){
            return n;
        }
        if(n==0){
            return m;
        }

        if(a[m-1]==b[m-1]){
            return 1+helper(a,b,m-1,n-1);
        }

        return 1+min(helper(a,b,m-1,n),helper(a,b,m,n-1));
    }
    string shortestCommonSupersequence(string str1, string str2) {
        string text1=str1;
        string text2=str2;
        
        vector<vector<int>> dp(text1.length()+1,vector<int>(text2.length()+1,0));
    
        for(int i=1;i<text1.length()+1;i++){
            for(int j=1;j<text2.length()+1;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        string res="";
        int i=text1.length();
        int j=text2.length();

        while(i>0 && j>0){
            if(text1[i-1]==text2[j-1]){
                res+=text1[i-1];
                i--;
                j--;
            }else if(dp[i-1][j]>dp[i][j-1]){
                res+=text1[i-1];
                i--;
            }else{
                res+=text2[j-1];
                j--;
            }
        }

        while(i>0){
            res+=text1[i-1];
            i--;
        }
        while(j>0){
            res+=text2[j-1];
            j--;
        }

        reverse(res.begin(),res.end());

        return res;
    }
};