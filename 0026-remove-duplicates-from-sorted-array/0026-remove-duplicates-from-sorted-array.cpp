class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int,int> hm;
        for(int x:nums){
            hm[x]++;
        }
        int i=0;
        for(auto p:hm){
            nums[i]=p.first;
            i++;
        }
        return i;
    }
};