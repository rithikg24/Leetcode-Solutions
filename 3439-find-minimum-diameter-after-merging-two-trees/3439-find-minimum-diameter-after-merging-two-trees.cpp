class Solution {
public:
    int  maxi1,  maxi2;

    int solve(int node, int par, vector<vector<int>>& adj,int& maxi) {
        
        if (adj[node].size() == 1 && par != -1) {
            return 1; 
        }
        int m1 = 0; 
        int m2 = 0; 

        for (auto neighbor : adj[node]) {
            if (neighbor == par) continue; 
            int height = solve(neighbor, node, adj, maxi);
            if (height > m1) {
                m2 = m1;
                m1 = height;
            } else if (height > m2) {
                m2 = height;
            }
        }

        maxi = max(maxi, m1 + m2); 

        return m1 + 1; 
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n1 = edges1.size() + 1; 
        int n2 = edges2.size() + 1; 

        vector<vector<int>> adj1(n1), adj2(n2);
        for (auto& edge : edges1) {
            adj1[edge[0]].push_back(edge[1]);
            adj1[edge[1]].push_back(edge[0]);
        }
        for (auto& edge : edges2) {
            adj2[edge[0]].push_back(edge[1]);
            adj2[edge[1]].push_back(edge[0]);
        }

        maxi1 = maxi2 = INT_MIN;

        solve(0, -1, adj1,  maxi1);
        solve(0, -1, adj2,  maxi2);


        int combinedDiameter =
            ceil(maxi1/ 2.0) + ceil(maxi2/ 2.0) + 1;        
        int largestExistingDiameter = max(maxi1, maxi2);  
        return max(combinedDiameter, largestExistingDiameter);
    }
};