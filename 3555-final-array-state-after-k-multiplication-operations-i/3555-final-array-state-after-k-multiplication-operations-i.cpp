class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int index=0;
       
       for(int i=0;i<k;i++)
       {
         int big=nums[0];
         index=0;
        for(int j=1;j<nums.size();j++)
        {
            if(big>nums[j])
            {
              big=nums[j];
                index=j;
             }
    
        }
        nums[index]=nums[index]*multiplier;
       }
       return nums;
    }


};