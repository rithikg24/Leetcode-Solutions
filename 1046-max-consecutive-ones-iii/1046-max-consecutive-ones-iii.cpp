class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0;
        int j=0;

        int cnt=0;

        int z=0;
        int o=0;

        while(j<nums.size()){
            if(nums[j]==0) z++;

            while(z>k){
                if(nums[i]==0) z--;
                i++;
            }
            cnt=max(cnt,j-i+1);
            j++;
        }
        return cnt;
    }
};