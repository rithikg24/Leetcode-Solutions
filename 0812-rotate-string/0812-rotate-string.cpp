class Solution {
public:
    bool rotateString(string s, string goal) {
        string tot=s+s;
        for(int i=0;i<s.length();i++){
            if(tot.substr(i,s.length())==goal){
                cout<<tot.substr(i,i+6);
                return true;
            }
        }
        return false;
    }
};