class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> prefix(arr.size());
        prefix[0]=arr[0];
        for(int i=1;i<arr.size();i++){
            prefix[i]=prefix[i-1]^arr[i];
        }
        vector<int> res;

        for(auto x:queries){
            res.push_back(prefix[x[1]]^prefix[x[0]]^arr[x[0]]);
        }

        return res;
    }
};