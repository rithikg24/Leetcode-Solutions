class Solution {
public:
    bool isSubsequence(string s, string t) {
        // int sptr=0;
        // int tptr=0;

        // while(tptr<t.length()){
        //     if(s[sptr]==t[tptr]) sptr++;
        //     tptr++;
        // }
        // if(sptr==s.length()){
        //     return true;
        // }
        // return false;
        return isSubsequenceFunc(s,t,0,0);
    }

    bool isSubsequenceFunc(string s, string t,int sp,int tp) {
        if(sp==s.length()){
            return true;
        }
        if(tp==t.length()){
            return false;
        }
        if(s[sp]==t[tp]) return isSubsequenceFunc(s,t,sp+1,tp+1);
        else return isSubsequenceFunc(s,t,sp,tp+1);
    }
};