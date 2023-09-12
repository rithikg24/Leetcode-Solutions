class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rowIdx=0,colIdx=matrix[0].size()-1;
        while(rowIdx<matrix.size() && colIdx>=0){
            if(matrix[rowIdx][colIdx]==target){
                return true;
            }else if(matrix[rowIdx][colIdx]<target){
                rowIdx++;
            }else{
                colIdx--;
            }
        }
        return false;
    }
};