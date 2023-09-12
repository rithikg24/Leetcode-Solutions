class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> hm;
        if(s.length()!=t.length()){
            return false;
        }
        for(char c:s){
            hm[c]++;
        }
        for(char c:t){
            if(hm.count(c)==1){
                hm[c]--;
                if(hm[c]==0){
                    hm.erase(c);
                }
            }else{
                return false;
            }
        }
        if(!hm.empty()){
            return false;
        }
        return true;
    }
};