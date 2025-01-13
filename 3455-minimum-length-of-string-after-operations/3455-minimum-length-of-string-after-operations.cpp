class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char,int> hm;
        int r=0;
        for(char c:s){
            hm[c]++;
            if(hm[c]==3){
                hm[c]-=2;
                r+=2;
            }
        }
        return s.length()-r;
    }
};