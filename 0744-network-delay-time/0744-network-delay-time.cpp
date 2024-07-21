class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1]; // node - time

        for(auto x : times) {
            adj[x[0]].push_back({x[1], x[2]});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        vector<int> time(n+1, INT_MAX);
        time[k] = 0;

        pq.push({0, k});

        while(!pq.empty()) {
            int nd = pq.top().second;
            int t = pq.top().first;
            pq.pop();

            for(auto x : adj[nd]) {
                int newNd = x.first;
                int newT = x.second;

                if(t + newT < time[newNd]) {
                    time[newNd] = t + newT;
                    pq.push({time[newNd], newNd});
                }
            }
        }

        int maxi = -1;

        for(int i = 1; i <= n; i++) {
            if(time[i] == INT_MAX) return -1;
            maxi = max(maxi, time[i]);
        }
        return maxi;
    }
};
