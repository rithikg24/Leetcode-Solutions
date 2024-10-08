class Solution {
public:
    int beautySum(string s) {
        int beautySum=0;
        for(int i=0;i<s.length();i++){
            unordered_map<char,int> hm;
            for(int j=i;j<s.length();j++){
                hm[s[j]]++;
                int minFreq=INT_MAX;
                int maxFreq=0;
                for(auto pair:hm){
                minFreq=min(minFreq,pair.second);
                maxFreq=max(maxFreq,pair.second);
                }
                int beauty= maxFreq-minFreq;
                beautySum+=beauty;
            }
        }

        return beautySum;
    }
};