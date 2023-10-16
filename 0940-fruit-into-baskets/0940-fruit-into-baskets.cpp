class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l=0;
        int r=0;

        int ans=0;
        unordered_map<int,int> hm;

        while(r<fruits.size()){
            if(hm.count(fruits[r])){
                hm[fruits[r]]++;
            }else{
                if(hm.size()==2){
                    while(hm.size()==2){
                        hm[fruits[l]]--;
                        if(hm[fruits[l]]==0){
                            hm.erase(fruits[l]);
                        }
                        l++;
                    }
                }
                hm[fruits[r]]=1;
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};