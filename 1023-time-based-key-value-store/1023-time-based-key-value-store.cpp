class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> hm;

    TimeMap() {}

    void set(string key, string value, int timestamp) {
        hm[key].emplace_back(timestamp, value);
    }

    string get(string key, int timestamp) {
        if (hm.find(key) == hm.end()) {
            return "";
        }

        const vector<pair<int, string>>& t = hm[key];
        int low = 0, high = t.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (t[mid].first == timestamp) {
                return t[mid].second;
            } else if (t[mid].first < timestamp) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return high >= 0 ? t[high].second : "";
    }
};