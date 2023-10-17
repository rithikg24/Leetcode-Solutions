class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
                nums[i]=0;
            }else{
                nums[i]=1;
            }
            cout<<nums[i]<<endl;
        }

        // Now the problem becomes number of subarrays with the sum k
        int cnt=0;
        int sum=0;
        unordered_map<int,int> hm;
        hm[0]=1;

        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int diff = sum-k;

            if(hm.count(diff)){
                cnt+=hm[diff];
            }
            hm[sum]++;
        }

        return cnt;
    }
};