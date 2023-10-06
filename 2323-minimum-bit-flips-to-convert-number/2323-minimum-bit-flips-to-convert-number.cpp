class Solution {
public:
    // Take xor of start and goal and then count no. of ones
    int minBitFlips(int start, int goal) {
        int res=start^goal;
        int cnt=0;
        while(res!=0){
            res=res&(res-1);
            cnt++;
        }
        return cnt;
    }
};