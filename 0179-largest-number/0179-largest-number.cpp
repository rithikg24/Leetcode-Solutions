bool cmp(int a, int b) {
    string sa = to_string(a);
    string sb = to_string(b);

    // Custom comparison to check which concatenation is larger
    if((sa + sb )> (sb + sa)){
        return true;
    }
    return false;
}
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);

        if (nums[0] == 0) {
            return "0";
        }

        string res = "";
        for (int x : nums) {
            res += to_string(x);
        }

        return res;
    }
};