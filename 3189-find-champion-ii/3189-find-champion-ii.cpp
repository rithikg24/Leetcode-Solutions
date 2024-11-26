class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n,0);

        for(auto x:edges){
            indegree[x[1]]++;
        }

        int cnt=0;
        int res=0;

        for(int i=0;i<n;i++){
            int x=indegree[i];
            if(x==0){
                if(cnt>0){
                    return -1;
                }
                cnt++;
                res=i;
            }
        }
        return res;
    }
};