class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n); // node-cost adjacency list

        for (auto& x : flights) {
            adj[x[0]].push_back({x[1], x[2]});
        }

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        // Priority queue: (cost, stops, node)
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, src}});

        while (!pq.empty()) {
            int stops = pq.top().first;
            int cost = pq.top().second.first;
            int node = pq.top().second.second;
            pq.pop();

            if (stops > k) continue; // Ignore if stops exceed k

            for (auto& x : adj[node]) {
                int next_node = x.first;
                int next_cost = x.second;

                if (cost + next_cost < dist[next_node]) {
                    dist[next_node] = cost + next_cost;
                    pq.push({stops+1, {cost + next_cost, next_node}});
                }
            }
        }
        if(dist[dst]==INT_MAX) return -1;
        return dist[dst];
        // return -1;
    }
};