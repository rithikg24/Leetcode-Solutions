class Solution {
public:
    void dfs(int node,vector<int> &vis,vector<int> adj[]){
        vis[node]=1;

        for(int x:adj[node]){
            if(!vis[x]){
                dfs(x,vis,adj);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int edges = connections.size();
        if(edges<n-1) return -1;

        // find the number the dsiconnected componenets and return it;
        vector<int> adj[n];
        for(auto x:connections){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }

        int cnt=0;
        vector<int> vis(n,0);

        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,vis,adj);
                cnt++;
            }
        }

        return cnt-1;

    }
};