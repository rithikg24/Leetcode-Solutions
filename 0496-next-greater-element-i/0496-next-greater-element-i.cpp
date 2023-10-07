class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        for(int x:nums1){
            for(int i=0;i<nums2.size();i++){
                if(x==nums2[i]){
                    int nextGreat=-1;
                    int k=i+1;
                    while(k<nums2.size() && nums2[k]<x){
                        k++;
                    }
                    if(k>i && k<nums2.size()){
                        nextGreat=nums2[k];
                    }
                    res.push_back(nextGreat);
                }
            }
        }
        return res;
    }
};