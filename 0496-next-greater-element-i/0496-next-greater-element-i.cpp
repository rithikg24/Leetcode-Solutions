class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res(nums1.size(),-1);

        unordered_map<int,int> hm;
        for(int i=0;i<nums1.size();i++){
            hm[nums1[i]]=i;
        }

        stack<int> s;

        for(int x:nums2){
           if(s.empty()){
                if(hm.count(x)){
                    s.push(x);
                }
            }else{
                if(x<s.top()){
                    if(hm.count(x)){
                        s.push(x);
                    }
                }else{
                    while(!s.empty() && s.top()<x){
                        res[hm[s.top()]]=x;
                        s.pop();
                    }
                    if(hm.count(x)){
                        s.push(x);
                    }
                }
            }
        }

        return res;
    }
};