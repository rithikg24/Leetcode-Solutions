class Solution {
public:
    int mod=1e9+7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> subSum;

        for(int i=0;i<n;i++){
            int s=0;
            for(int j=i;j<n;j++){
                s+=nums[j];
                subSum.push_back(s);
            }
        }
        sort(subSum.begin(),subSum.end());
        int res=0;
        for(int i=left-1;i<right;i++){
            res+=subSum[i];
            res=res%mod;
        }
        return res;
    }
};