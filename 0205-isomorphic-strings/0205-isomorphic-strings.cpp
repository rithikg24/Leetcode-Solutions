class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> hm;
        set<char> track;
        if(s.length()!=t.length()){
            return false;
        }

        for(int i=0;i<s.length();i++){
            if(hm.count(s[i])==0){
                if(track.count(t[i])==0){
                    hm[s[i]]=t[i];
                    track.insert(t[i]);
                }else{
                    return false;
                }
            }else{
                if(hm[s[i]]!=t[i]){
                    return false;
                }
            }
        }

        return true;
    }
};