class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();

        sort(nums.begin(),nums.end());

        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            int j=i+1;
            int k=n-1;

            while(j<k){
                int s = nums[i]+nums[j]+nums[k];
                if(s<0){
                    j++;
                }else if(s>0){
                    k--;
                }else{
                    res.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    while(j<k && nums[j]==nums[j-1]){
                        j++;
                    }
                    k--;
                    while(j<k && nums[k]==nums[k+1]){
                        k--;
                    }
                }
            }
        }

        return res;
    }
};