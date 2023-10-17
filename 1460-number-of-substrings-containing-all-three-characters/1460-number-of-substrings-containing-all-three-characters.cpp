class Solution {
public:
    int numberOfSubstrings(string s) {
        int l=0;
        int r=0;

        int cnt=0;

        unordered_map<char,int> hm;

        while(r<=s.length()){
            // all three found
            if(hm.size()==3){
                cnt+=(s.length()-r+1);
                hm[s[l]]--;
                if(hm[s[l]]==0){
                    hm.erase(s[l]);
                }
                l++;
                continue;
            }

            hm[s[r]]++;
            r++;
        }
        return cnt;
    }
};