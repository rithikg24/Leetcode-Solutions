class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        // Directions array for N, E, S, W (North, East, South, West)
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        // Current position of the robot
        int x = 0, y = 0;
        // Current direction index (0: N, 1: E, 2: S, 3: W)
        int dir = 0;

        // Set of obstacle positions
        set<pair<int, int>> st;
        for (auto& obs : obstacles) {
            st.insert({obs[0], obs[1]});
        }

        int maxDist = 0;

        // Iterate through each command
        for (int cmd : commands) {
            if (cmd == -1) { // Turn right
                dir = (dir + 1) % 4;
            } else if (cmd == -2) { // Turn left
                dir = (dir + 3) % 4; // Equivalent to turning left by 90 degrees
            } else { // Move forward cmd steps
                for (int step = 0; step < cmd; ++step) {
                    int newX = x + directions[dir].first;
                    int newY = y + directions[dir].second;
                    // Check if the next position is an obstacle
                    if (st.find({newX, newY}) == st.end()) {
                        x = newX;
                        y = newY;
                        // Update the maximum distance
                        maxDist = max(maxDist, x * x + y * y);
                    } else {
                        // If there's an obstacle, stop moving forward
                        break;
                    }
                }
            }
        }

        return maxDist;
    }
};
