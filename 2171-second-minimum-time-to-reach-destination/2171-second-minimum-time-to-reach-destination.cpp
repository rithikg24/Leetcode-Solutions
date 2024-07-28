class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // cost, node
        vector<int> adj[n + 1];
        for (auto x : edges) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }

        // Visit count array to track the number of unique visits
        vector<int> visitCount(n + 1, 0);
        
        // Minimum distance array to store the minimum time to reach each node
        vector<int> minDistance(n + 1, -1);

        pq.push({0, 1});

        while (!pq.empty()) {
            int cost = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            // Skip if this node has been visited twice already
            if (minDistance[node]==cost || visitCount[node] >= 2) {
                continue;
            }

            visitCount[node]++;
            minDistance[node] = cost;

            // If node n is reached for the second time, return the cost
            if (node == n && visitCount[node] == 2) {
                return cost;
            }

            // Calculate the reach time considering the traffic signal
            int reachTime = cost;
            if ((reachTime / change) % 2 != 0) {
                reachTime += change - (reachTime % change);
            }

            // Push all adjacent nodes with updated times into the priority queue
            for (auto x : adj[node]) {
                int newNode = x;
                int newTime = reachTime + time;
                pq.push({newTime, newNode});
            }
        }
        return -1;
    }
};
