class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int totalSum=0;
        for(int x:nums){
            totalSum+=x;
        }
        if(totalSum==x){
            return nums.size();
        }
        totalSum=totalSum-x;

        int max_len = 0, cur_sum = 0, left = 0;
        
        for (int right = 0; right < nums.size(); ++right) {
            cur_sum += nums[right];
            while (left <= right && cur_sum > totalSum) {
                cur_sum -= nums[left];
                left++;
            }
            if (cur_sum == totalSum) {
                max_len = max(max_len, right - left + 1);
            }
        }
        
        return max_len ? nums.size() - max_len : -1;
    }
};