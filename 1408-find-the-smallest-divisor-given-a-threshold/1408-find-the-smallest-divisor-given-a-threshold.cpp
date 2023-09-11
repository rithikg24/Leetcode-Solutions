class Solution {
public:
    int findMax(vector<int> nums){
        int maxNum=INT_MIN;
        for(int x:nums){
            maxNum=max(x,maxNum);
        }
        return maxNum;
    }

    long func(vector<int> nums,int n){
        long ans=0;
        for(int x:nums){
            long t=ceil((double)x/(double)n);
            ans=ans+t;
        }
        return ans;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int s=1,e=findMax(nums);

        while(s<=e){
            int m=(s+e)/2;
            int a=func(nums,m);
            if(a>threshold){
                s=m+1;
            }else{
                e=m-1;
            }
        }

        return s;

    }
};