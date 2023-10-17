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

        // // Now the problem becomes number of subarrays with the sum k
        // int cnt=0;
        // int sum=0;
        // unordered_map<int,int> hm;
        // hm[0]=1;

        // for(int i=0;i<nums.size();i++){
        //     sum+=nums[i];
        //     int diff = sum-k;

        //     if(hm.count(diff)){
        //         cnt+=hm[diff];
        //     }
        //     hm[sum]++;
        // }

        // return cnt;
        return atmost(nums,k)-atmost(nums,k-1);
    }

    int atmost(vector<int>& nums,int k){
        int s=0;
        int cnt=0;
        int l=0;
        int r=0;

        while(r<nums.size()){
            s+=nums[r];
            while(s>k){
                s-=nums[l];
                l++;
            }
            int len = r-l+1;
            cnt+=len;
            r++;
        }

        return cnt;
    }
};