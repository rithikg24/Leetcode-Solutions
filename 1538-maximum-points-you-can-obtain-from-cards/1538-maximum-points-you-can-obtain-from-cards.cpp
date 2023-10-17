class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int totalSum=0;
        for(int x:cardPoints){
            totalSum+=x;
        }
        if(k==cardPoints.size()) return totalSum;
        int minSum=INT_MAX;

        int s=0;
        int l=0;
        int r=0;

        while(r<cardPoints.size()){
            s+=cardPoints[r];
            r++;
            if(r>cardPoints.size()-k){
                s-=cardPoints[l];
                l++;
            }
            if(r>cardPoints.size()-k-1){
                minSum = min(s,minSum);
            }
        }

        return totalSum-minSum;

    }
};