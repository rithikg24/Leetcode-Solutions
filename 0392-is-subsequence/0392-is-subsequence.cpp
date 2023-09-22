class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sptr=0;
        int tptr=0;

        while(tptr<t.length()){
            if(s[sptr]==t[tptr]) sptr++;
            tptr++;
        }
        if(sptr==s.length()){
            return true;
        }
        return false;
    }
};