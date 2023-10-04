class Solution {
public:
    bool isValid(vector<string> &board,int row,int col,int n){
        // checking top
        for(int i=row;i>=0;i--){
            if(board[i][col]=='Q'){
                return false;
            }
        }

        //check left
        for(int j=col;j>=0;j--){
            if(board[row][j]=='Q'){
                return false;
            }
        }

        //check left diagonal
        for(int i=row,j=col;i>=0 && j>=0;i--,j--){
            if(board[i][j]=='Q'){
                return false;
            }
        }

        //check left down diagonal
        for(int i=row,j=col;i<n && j>=0;i++,j--){
            if(board[i][j]=='Q'){
                return false;
            }
        }

        return true;
    }

    void solve(vector<vector<string>> &res,vector<string> board,int col,int n){
        if(col>=n){
            res.push_back(board);
            return;
        }
        for(int i=0;i<n;i++){
            if(isValid(board,i,col,n)){
                board[i][col]='Q';
                solve(res,board,col+1,n);
                board[i][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n,'.'));

        solve(res,board,0,n);
        return res;
    }
};