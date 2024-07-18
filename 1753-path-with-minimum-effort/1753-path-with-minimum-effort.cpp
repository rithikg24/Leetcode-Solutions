class Solution {
public:
     int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        vector<vector<int>>dist(m,vector<int>(n,1e9));
        dist[0][0]=0;
        int dr[4]={-1,0,1,0};
        int dc[4]={0,1,0,-1};
        while(!pq.empty())
        {
            int e=pq.top().first;
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            pq.pop();
            if(r==m-1 && c==n-1)
            return e;
            for(int i=0;i<4;i++)
            {
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 && nr<m && nc>=0 && nc<n )
                {
                    int ne=max(abs(heights[r][c]-heights[nr][nc]),e);
                    if(ne<dist[nr][nc])
                    {
                        dist[nr][nc]=ne;
                        pq.push({ne,{nr,nc}});
                    }
                }
            }
        }
        return -1;
    }
};