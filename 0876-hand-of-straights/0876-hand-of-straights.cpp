class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0) return false;

        sort(hand.begin(),hand.end());

        unordered_map<int,int> hm;

        for(int x:hand){
            hm[x]++;
        }
        
        for(int x:hand){
            if(hm[x]==0) continue;

            for(int i=0;i<groupSize;i++){
                if(hm[x+i]>0){
                    hm[x+i]--;
                }else{
                    return false;
                }
            }
            
        }

        return true;
    }
};