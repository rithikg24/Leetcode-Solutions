class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0;
        int r=0;

        int flip=0;
        int ans=0;

        while(r<nums.size()){
            if(nums[r]==0){
                flip++;
            }

            while(flip>k){
                if(nums[l]==0){
                    flip--;
                }
                l++;
            }

            int nOnes = r-l+1;
            ans = max(ans,nOnes);
            r++;
        }

        return ans;
    }
};