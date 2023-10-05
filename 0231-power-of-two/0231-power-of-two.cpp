class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0) return false;
        int res=n&(n-1);
        if(!res) return true;

        return false;
    }
};