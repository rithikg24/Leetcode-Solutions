class Solution {
private:
    vector<int> map;

    int newMappedNum(int a) const {
        if(a==0) return map[0];
        int na = 0;
        int k = 0;
        while (a != 0) {
            int p = a % 10;
            na = na + (map[p] * static_cast<int>(pow(10, k)));
            a = a / 10;
            k++;
        }
        return na;
    }

public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        map = mapping;
        unordered_map<int, int> hm;
        for (int x : nums) {
            hm[x] = newMappedNum(x);
        }
        sort(nums.begin(), nums.end(), [this, &hm](const int &a, const int &b) {
            return hm[a] < hm[b];
        });
        return nums;
    }
};