class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size();i++){
            for(int j=i+1;j<matrix[i].size();j++){
                int x = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = x;
            }
        }
        for(int col=0;col<(matrix[0].size()/2);col++){
            for(int row=0;row<matrix.size();row++){
                int x = matrix[row][col];
                matrix[row][col] = matrix[row][matrix.size()-1-col];
                matrix[row][matrix.size()-1-col] = x;
            }
        }
    }
    void transpose(vector<vector<int>>& matrix){
        
    }
};