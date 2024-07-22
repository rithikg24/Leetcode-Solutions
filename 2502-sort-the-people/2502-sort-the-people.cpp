bool cmp(const pair<int,string> &a,const pair<int,string> &b){
    return a.first>b.first;
}
class Solution {
public:
    
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int,string>> v;
        for(int i=0;i<names.size();i++){
            v.push_back({heights[i],names[i]});
        }
        sort(v.begin(),v.end(),cmp);
        for(int i=0;i<names.size();i++){
            names[i]=v[i].second;
        }
        return names;
    }
};