class Solution {
public:
    long long findTotaltime(vector<int> piles, int k){
        long long totalTime=0;
        for(int x:piles){
            totalTime+=ceil(x/(double)k);
        }
        return totalTime;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int s=1;
        int e=piles[0];
        for(int x:piles){
            e=max(e,x);
        }

        while(s<=e){
            int m=(s+e)/2;
            long long t=findTotaltime(piles,m);
            if(t>h){
                s=m+1;
            }else{
                e=m-1;
            }
        }
        return s;
    }
};