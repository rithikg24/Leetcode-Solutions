class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int> hm;
        for(int x:arr1) hm[x]++;

        vector<int> res;

        for(int x:arr2){
            while(hm[x]!=0){
                res.push_back(x);
                hm[x]--;
            }
            hm.erase(x);
        }
        for(auto x:hm){
            int val=x.first;
            int n=x.second;
            for(int i=0;i<n;i++){
                res.push_back(val);
            }
        }
        return res;
    }
};