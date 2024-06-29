class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> res(n);
        vector<vector<int>> graph(n);
        
        // Build the graph
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
        }
        
        // Perform DFS from each node
        for (int i = 0; i < n; ++i) {
            vector<bool> visited(n, false);
            dfs(graph, i, i, res, visited);
        }
        
        // Sort the ancestors list for each node
        for (int i = 0; i < n; ++i) {
            sort(res[i].begin(), res[i].end());
        }
        
        return res;
    }

private:
    void dfs(const vector<vector<int>>& graph, int parent, int curr, vector<vector<int>>& res, vector<bool>& visited) {
        visited[curr] = true;
        for (int neighbor : graph[curr]) {
            if (!visited[neighbor]) {
                res[neighbor].push_back(parent);
                dfs(graph, parent, neighbor, res, visited);
            }
        }
    }
};
