class Solution {
public:
    long long maximumTotalSum(vector<int>& mhs) {
        sort(mhs.begin(), mhs.end());
        long long sum = 0;
        int last = INT_MAX;
        for (int i = mhs.size() - 1; i >= 0; i--) {
            int assigned_value = min(mhs[i], last - 1);
            if (assigned_value <= 0) return -1;
            sum += assigned_value;
            last = assigned_value;
        }
        return sum;
    }
};
