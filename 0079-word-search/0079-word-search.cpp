class Solution {
public:
    vector<pair<int,int>> find(char c,pair<int,int> loc,vector<vector<char>>& board){
        int i=loc.first;
        int j=loc.second;
        vector<pair<int,int>> res;
        if((i!=0 && board[i-1][j]==c)){
            res.push_back({i-1,j});
        }
        if(i!=board.size()-1 && board[i+1][j]==c){
            res.push_back({i+1,j});
        }
        if(j!=0 && board[i][j-1]==c){
            res.push_back({i,j-1});
        }
        if(j!=board[0].size()-1 && board[i][j+1]==c){
            res.push_back({i,j+1});
        }

        return res;
    }

    void helper(vector<vector<char>>& board,pair<int,int> initial,string word,int i,bool &finish){
        if(i==word.length()){
            finish=true;
            return;
        }
        vector<pair<int,int>> found=find(word[i],initial,board);
        if(found.size()==0){
            return;
        }
        for(auto x:found){
            char tmp=board[x.first][x.second];
            board[x.first][x.second]='.';
            helper(board,x,word,i+1,finish);
            board[x.first][x.second]=tmp;
        }
    }

    bool exist(vector<vector<char>>& board, string word) {
        vector<pair<int,int>> ini;
        bool res=false;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(board[i][j]==word[0]){
                    ini.push_back({i,j});
                }
            }
        }
        if(ini.empty()){
            return false;
        }

        for(auto x:ini){
            char tmp=board[x.first][x.second];
            board[x.first][x.second]='.';
            helper(board,x,word,1,res);
            board[x.first][x.second]=tmp;
        }

        return res;
    }
};