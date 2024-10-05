class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> s1map;

        for(char c:s1){
            s1map[c]++;
        }

        unordered_map<char,int> hm;
        int i=0;
        int j=0;

        while(j<s2.length()){
            hm[s2[j]]++;
            if(j>=s1.length()-1){
                if(hm==s1map) return true;
                hm[s2[i]]--;
                if(hm[s2[i]]==0){
                    hm.erase(s2[i]);
                }
                i++;
            }
            j++;
        }

        return false;
    }
};