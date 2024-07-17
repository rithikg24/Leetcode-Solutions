class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int> adj[V];
        // reverse graph
        for(int i=0;i<V;i++){
            for(int x:graph[i]){
                adj[x].push_back(i);
            }
        }
        vector<int> topo;
        vector<int> indegree(V,0);
        queue<int> q;

        for(int i=0;i<V;i++){
            for(int x:adj[i]){
                indegree[x]++;
            }
        }

        for(int i=0;i<V;i++){
            if(indegree[i]==0) q.push(i);
        }

        while(!q.empty()){
            int ver = q.front();
            q.pop();
            topo.push_back(ver);

            for(int x:adj[ver]){
                indegree[x]--;
                if(indegree[x]==0){
                    q.push(x);
                }
            }
        }

        sort(topo.begin(),topo.end());

        return topo;
    }
};