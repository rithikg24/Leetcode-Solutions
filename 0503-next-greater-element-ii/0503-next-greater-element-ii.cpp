class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res(nums.size(),-1);

        unordered_map<int,int> hm;
        for(int i=0;i<nums.size();i++){
            hm[nums[i]]=i;
        }

        stack<int> s;
        int n = nums.size();

        for(int i=0;i<2*n;i++){
            int x = nums[i%n];
           if(s.empty()){
                s.push(i%n);
            }else{
                if(x<nums[s.top()]){
                    s.push(i%n);
                }else{
                    while(!s.empty() && nums[s.top()]<x){
                        res[s.top()]=x;
                        s.pop();
                    }
                    s.push(i%n);
                }
            }
        }

        return res;
    }
};