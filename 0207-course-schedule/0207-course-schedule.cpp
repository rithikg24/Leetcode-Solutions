class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prereq) {
        vector<int> adj[numCourses];
        for(auto x:prereq){
            adj[x[0]].push_back(x[1]);
        }
        vector<int> topo;
        vector<int> indegree(numCourses,0);

        for(int i=0;i<numCourses;i++){
            for(int x:adj[i]){
                indegree[x]++;
            }
        }

        queue<int> q;

        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0) q.push(i);
        }

        while(!q.empty()){
            int ver=q.front();
            q.pop();

            topo.push_back(ver);

            for(int x:adj[ver]){
                indegree[x]--;
                if(indegree[x]==0){ q.push(x);}
            }
        }
        if(topo.size()!=numCourses) return false;
        return true;
    }
};