class Solution {
public:
    int minimumDeletions(string s) {
        vector<int> aright(s.length(),0);
        vector<int> bleft(s.length(),0);

        for(int i=s.length()-2;i>=0;i--){
            if(s[i+1]=='a'){
                aright[i]=aright[i+1]+1;
            }else{
                aright[i]=aright[i+1];
            }
        }
        for(int i=1;i<s.length();i++){
            if(s[i-1]=='b'){
                bleft[i]=bleft[i-1]+1;
            }else{
                bleft[i]=bleft[i-1];
            }
        }

        int mini=INT_MAX;
        for(int i=0;i<s.length();i++){
            mini=min(mini,aright[i]+bleft[i]);
        }

        return mini;
    }
};