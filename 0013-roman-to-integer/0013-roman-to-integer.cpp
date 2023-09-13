class Solution {
public:

    int romanToInt(string s) {
        unordered_map<char,int> hm;
        hm['I']=1;
        hm['V']=5;
        hm['X']=10;
        hm['L']=50;
        hm['C']=100;
        hm['D']=500;
        hm['M']=1000;

        int ans=0;
        for(int i=0;i<s.length();i++){
            if(hm[s[i]]<hm[s[i+1]]){
                ans=ans-hm[s[i]];
            }else{
                ans=ans+hm[s[i]];
            }
        }
        return ans;
    }
};