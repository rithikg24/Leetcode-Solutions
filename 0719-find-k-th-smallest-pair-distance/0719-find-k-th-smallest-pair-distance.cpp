class Solution {
public:
    int countPairs(vector<int> nums,int maxDist){
        int count = 0, j = 0;
        for (int i = 0; i < nums.size(); ++i) {
            while (j < nums.size() && nums[j] - nums[i] <= maxDist) ++j;
            count += j - i - 1;
        }
        return count;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int low = 0, high = nums[n - 1] - nums[0];

        while (low < high) {
            int mid = low + (high - low) / 2;
            if (countPairs(nums,mid) < k) low = mid + 1;
            else high = mid;
        }

        return low;
    }
};