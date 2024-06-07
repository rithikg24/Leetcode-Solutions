class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        vector<int> prev(n,0);
        vector<int> curr(n,0);

        for(int i=0;i<n;i++){
            prev[i] = matrix[0][i];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                // i-1 <-> j-1,j,j+1
                int top = prev[j];
                int topLeft = j-1>=0 ? prev[j-1] : INT_MAX;
                int topRight = j+1<n ? prev[j+1] : INT_MAX;

                curr[j] = matrix[i][j] + min(top,min(topLeft,topRight));
            }
            prev=curr;
        }
        int res = INT_MAX;
        for(int x:prev){
            res = min(res,x);
        }

        return res;
    }
};