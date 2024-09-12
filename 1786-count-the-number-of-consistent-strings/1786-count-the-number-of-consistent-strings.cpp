class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        set<char> hm;
        for(char c:allowed){
            hm.insert(c);
        }
        int cnt=0;
        for(string s:words){
            bool all=true;
            for(char c:s){
                if(hm.find(c)==hm.end()){
                    all=false;
                    break;
                }
            }
            if(all) cnt++;
        }
        return cnt;
    }
};