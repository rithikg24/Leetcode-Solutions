class Solution {
public:
    void dfs(vector<vector<int>>& image,int i, int j,int ini,int co,vector<vector<int>>& vis){   
        if(i>=image.size() || i<=-1) return;
        if(j>image[0].size() || j<=-1) return;
        if(image[i][j]!=ini) return;
        if(vis[i][j]==1) return;

        image[i][j]=co;
        vis[i][j]=1;

        if(i-1>=0 && image[i-1][j]==ini) dfs(image,i-1,j,ini,co,vis);
        if(j-1>=0 && image[i][j-1]==ini) dfs(image,i,j-1,ini,co,vis);
        if(i+1<image.size() && image[i+1][j]==ini) dfs(image,i+1,j,ini,co,vis);
        if(j+1<image[0].size() && image[i][j+1]==ini) dfs(image,i,j+1,ini,co,vis);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> vis(image.size(),vector<int>(image[0].size(),0));
        dfs(image,sr,sc,image[sr][sc],color,vis);
        return image;
    }
};