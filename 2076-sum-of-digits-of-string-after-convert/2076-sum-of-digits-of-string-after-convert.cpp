class Solution {
public:
    int sumOfDigits(int n){
        int sum=0;
        while(n){
            sum+=(n%10);
            n=n/10;
        }
        return sum;
    }
    int getLucky(string s, int k) {
        int res=0;
        for(char c:s){
            res+=sumOfDigits(c-'a'+1);
        }
        if(k==1) return res;
        for(int i=0;i<k-1;i++){
            res=sumOfDigits(res);
            if(res<10){
                return res;
            }
        }
        return res;
    }
};