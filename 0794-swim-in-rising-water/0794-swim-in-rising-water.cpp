class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        vector<vector<int>> vis(n,vector<int>(n,0));
        // time - (row,col)
        pq.push({grid[0][0],{0,0}});
        vis[0][0]=1;
        int t=0;
        while(!pq.empty()){
            int time=pq.top().first;
            int i=pq.top().second.first;
            int j=pq.top().second.second;
            pq.pop();
            // if(vis[i][j]==1) continue;
            if(i==n-1 && j==n-1) return time;
           
            // top i-1,j
            if(i>0){
                int nR=i-1;
                int nC=j;
                if(vis[nR][nC]==0){
                    pq.push({max(time,grid[nR][nC]),{nR,nC}});
                    vis[nR][nC]=1;
                }
                
            }
            //left i,j-1
            if(j>0){
                int nR=i;
                int nC=j-1;
               if(vis[nR][nC]==0){
                    pq.push({max(time,grid[nR][nC]),{nR,nC}});
                    vis[nR][nC]=1;
                }
            }
            // down i+1,j
            if(i+1<n){
                int nR=i+1;
                int nC=j;
                if(vis[nR][nC]==0){
                    pq.push({max(time,grid[nR][nC]),{nR,nC}});
                    vis[nR][nC]=1;
                }
            }
            //right i,j+1
            if(j+1<n){
                int nR=i;
                int nC=j+1;
                if(vis[nR][nC]==0){
                    pq.push({max(time,grid[nR][nC]),{nR,nC}});
                    vis[nR][nC]=1;
                }
            }
        }
        return -1;
    }
};