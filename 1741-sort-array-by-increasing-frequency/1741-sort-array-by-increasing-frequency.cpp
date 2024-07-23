bool cmp(const pair<int,int> &a,const pair<int,int> &b){
    if(a.first==b.first) return a.second>b.second;
    return a.first<b.first;
}
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> hm;
        for(int x:nums){
            hm[x]++;
        }
        vector<pair<int,int>> v;

        for(auto x:hm){
            v.push_back({x.second,x.first});
        }
        sort(v.begin(),v.end(),cmp);
        vector<int> res;
        for(auto x:v){
            int freq=x.first;
            int val = x.second;
            for(int i=0;i<freq;i++){
                res.push_back(val);
            }
        }
        return res;
    }
};