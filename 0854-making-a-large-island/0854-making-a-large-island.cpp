class DisjointSet{
	

public:

vector<int> size,parent;
DisjointSet(int n){
    
size.resize(n+1);
parent.resize(n+1);
for( int i=0;i<=n;i++){
	size[i]=1;
	parent[i]=i;
}

}
int findUpar(int val){
	if(parent[val]==val) return val;

	return parent[val]=findUpar(parent[val]);
}

void unionBysize(int u,int v){
	int ulp_u=findUpar(u);
	int ulp_v=findUpar(v);
	if(size[ulp_u]<size[ulp_v]){
		parent[ulp_u]=ulp_v;
		size[ulp_v]+=size[ulp_u];
	}
	else{
		parent[ulp_v]=ulp_u;
		size[ulp_u]+=size[ulp_v];
	}
}
};














class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
DisjointSet ds(n*m);
int one=0;
 vector<vector<int>> vis(n,vector<int>(m,0));
     for( int f=0;f<n;f++){
         for( int j=0;j<m;j++){
     if( grid[f][j]==1){
          one++;
      vis[f][j]=1;
      
      int ar[4]={-1,0,1,0};
      int ac[4]={0,-1,0,1};
      
      for( int i=0;i<4;i++){
          int adjr=f+ar[i];
          int adjc= j+ac[i];
          if(adjr>=0 && adjr<n && adjc>=0 && adjc<m){
              if(grid[adjr][adjc]==1){
                  int nodevalue= (m*f)+j;
                  int adjvalue=(m*adjr)+adjc;
                  if(ds.findUpar(nodevalue)!= ds.findUpar(adjvalue)){
                      ds.unionBysize(nodevalue,adjvalue);
                  }
              }
          }
      }
     }
         }
     }














        int sum=0;
        int mo=0;
 unordered_set<int> st;
       for( int i=0;i<grid.size();i++){
           for( int j=0;j<grid[0].size();j++){
               if(grid[i][j]==1) continue;
               int ar[4]={-1,0,+1,0};
               int ac[4]={0,1,0,-1};
               for( int k=0;k<4;k++){
                   int row=i+ar[k];
                   int col=j+ac[k];
                   if(row>=0 && row<grid.size() && col>=0 && col<grid[0].size()){
                       if(grid[row][col]==1){
                         
                       int adjvalue=(m*row)+col;
                          
                           int node=ds.findUpar(adjvalue);
                           st.insert(node);
                        
                          // cout<<node<<endl;

                       }
                   }

               }
              for( auto it: st){
                  sum+=ds.size[it];
//cout<<sum<<endl;
              }
mo= max(sum,mo);
sum=0;
st.clear();
           }
       }
if(one== n*m) return n*m;

       return (mo+1);
    }
};