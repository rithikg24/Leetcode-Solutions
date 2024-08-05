class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> hm;

        // Count the frequency of each string in the array
        for (string s : arr) {
            hm[s]++;
        }

        int cnt = 0;
        // Iterate over the array to maintain the order of elements
        for (string s : arr) {
            if (hm[s] == 1) {
                cnt++;
                if (cnt == k) {
                    return s;
                }
            }
        }

        // If there are fewer than k distinct strings, return an empty string
        return "";
    }
};