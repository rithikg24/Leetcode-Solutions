class DisjointSet {
private:
    vector<int> parent;
    vector<int> rank;

public:
    DisjointSet(int n) {
        rank.resize(n, 0);   
        parent.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findPar(int node) {
        if (parent[node] == node) return node;
        return parent[node] = findPar(parent[node]);
    }

    void unionByRank(int a, int b) {
        int apar = findPar(a);
        int bpar = findPar(b);

        if (apar == bpar) return;

        if (rank[apar] < rank[bpar]) {
            parent[apar] = bpar;
        } else if (rank[apar] > rank[bpar]) {
            parent[bpar] = apar;
        } else {
            parent[bpar] = apar;
            rank[apar]++;
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        unordered_map<string, int> hm;
        DisjointSet ds(n);
        int k = 0;
        for (auto& x : accounts) {
            for (int i = 1; i < x.size(); i++) {
                if (hm.count(x[i])) {
                    ds.unionByRank(k, hm[x[i]]);
                } else {
                    hm[x[i]] = k;
                }
            }
            k++;
        }

        vector<vector<string>> merged(n);
        for (auto& x : hm) {
            int par = ds.findPar(x.second);
            merged[par].push_back(x.first);
        }

        vector<vector<string>> res;
        for (int i = 0; i < n; i++) {
            if (merged[i].empty()) continue;
            sort(merged[i].begin(), merged[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for (auto& email : merged[i]) {
                temp.push_back(email);
            }
            res.push_back(temp);
        }

        return res;
    }
};