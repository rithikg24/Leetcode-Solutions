class DisjointSet{
    public:
    vector<int> parent;
    vector<int> rank;

    DisjointSet(int n){
        parent.resize(n,0);
        rank.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }

    int findParent(int n){
        if(parent[n]==n) return n;
        return parent[n]=findParent(parent[n]);
    }

    void unionByRank(int a,int b){
        int apar = findParent(a);
        int bpar = findParent(b);

        if(apar==bpar) return;

        if(rank[apar]>rank[bpar]){
            parent[bpar]=apar;
        }else if(rank[apar]<rank[bpar]){
            parent[apar]=bpar;
        }else{
            parent[bpar]=apar;
            rank[bpar]++;
        }
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DisjointSet dj(edges.size()+1);
        for(auto x:edges){
            int u=x[0];
            int v=x[1];
            if(dj.findParent(u)!=dj.findParent(v)){
                dj.unionByRank(u,v);
            }else{
                return {u,v};
            }
        }
        return {};
    }
};