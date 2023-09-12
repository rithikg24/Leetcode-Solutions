class Solution {
public:
    string rotate(string s,int k){
        string res="";

        for(int i=k;i<s.length();i++){
            res+=s[i];
        }
        for(int i=0;i<k;i++){
            res+=s[i];
        }
        return res;
        
    }
    bool rotateString(string s, string goal) {
        for(int i=0;i<s.length();i++){
            if(rotate(s,i)==goal){
                return true;
            }
        }
        return false;
    }
};