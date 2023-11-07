class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxRes=0;
        int maxLoc=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]){
                maxLoc++;
            }else{
                maxLoc=0;
            }
            maxRes = max(maxRes,maxLoc);
        }
        return maxRes;
    }
};