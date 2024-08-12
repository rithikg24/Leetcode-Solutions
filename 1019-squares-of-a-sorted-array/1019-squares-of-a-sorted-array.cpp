// Two Pointers (Optimal).
// T.C. -> O(N).
// S.C. -> O(N).

class Solution {
public:
    vector<int> sortedSquares(vector<int> &nums) {
        int n = nums.size();
        int low = 0, high = n - 1, k = n - 1;
        vector<int> ans (n);

        while (low <= high) {

            int left = nums[low] * nums[low];
            int right = nums[high] * nums[high];

            if (left >= right) {

                ans[k] = left;
                k--;
                low++;
            }
            else {

                ans[k] = right;
                k--;
                high--;
            }
        }

        return ans;
    }
};