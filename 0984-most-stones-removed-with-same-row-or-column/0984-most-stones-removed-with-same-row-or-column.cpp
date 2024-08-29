class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        UnionFind ufObj(20002);
        for (auto& stone : stones) {
            int row = stone[0];
            int col = stone[1] + 10001;
            ufObj.unionNodes(row, col);
        }
        unordered_set<int> uniqueRoots;
        for (auto& stone : stones) {
            uniqueRoots.insert(ufObj.find(stone[0]));
        }
        return n - uniqueRoots.size();
    }

private:
    class UnionFind {
    public:
        UnionFind(int size) : parent(size), rank(size, 1) {
            for (int node = 0; node < size; ++node) {
                parent[node] = node;
            }
        }

        int find(int node) {
            if (parent[node] != node) {
                parent[node] = find(parent[node]);
            }
            return parent[node];
        }

        void unionNodes(int node1, int node2) {
            int grpHead1 = find(node1);
            int grpHead2 = find(node2);
            if (grpHead1 != grpHead2) {
                if (rank[grpHead1] > rank[grpHead2]) {
                    parent[grpHead2] = grpHead1;
                } else if (rank[grpHead1] < rank[grpHead2]) {
                    parent[grpHead1] = grpHead2;
                } else {
                    parent[grpHead2] = grpHead1;
                    rank[grpHead1]++;
                }
            }
        }

    private:
        vector<int> parent;
        vector<int> rank;
    };
};