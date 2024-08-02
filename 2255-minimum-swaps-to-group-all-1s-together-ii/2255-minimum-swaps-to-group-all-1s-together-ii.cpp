class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int o=0;
        int z=0;
        vector<int> t=nums;
        t.insert(t.end(),nums.begin(),nums.end());
        int j=0;
        int tot=0;
        for(int x:nums){
            if(x==1){
                tot++;
            }
        }
        int maxi=0;
        for(int i=0;i<t.size();i++){
            if(t[i]==1){
                o++;
            }else{
                z++;
            }

            if((i-j+1)==tot){
                maxi=max(maxi,o);
                if(t[j]==1){
                    o--;
                }else{
                    z--;
                }
                j++;
            }
        }
        return tot-maxi;
    }
};