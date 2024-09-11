class Solution {
public:
    int countSetBits(int n) {
        int count = 0;
        while (n) {
            n &= (n - 1); // Turn off the rightmost set bit
            count++;
        }
        return count;
    }
    int minBitFlips(int start, int goal) {
        int cntNum = start^goal;
        return countSetBits(cntNum);
    }
};