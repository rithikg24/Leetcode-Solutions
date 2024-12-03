class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string res="";
        set<int> sp(spaces.begin(),spaces.end());
        if(sp.find(0)!=sp.end()){
            res+=" ";
        }
        for(int i=0;i<s.length();i++){
            res+=s[i];
            if(sp.find(i+1)!=sp.end()){
                res+=" ";
            }
        }
        return res;
    }
};