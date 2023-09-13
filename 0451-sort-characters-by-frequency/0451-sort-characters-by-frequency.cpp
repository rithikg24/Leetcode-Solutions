class Solution {
public:
    
    string frequencySort(string s) {
        unordered_map<char,int> hm;
        string res="";
        for(char c:s){
            hm[c]++;
        }
        while(!hm.empty()){
            int maxFreq=0;
            char ele;
            for(auto pair:hm){
                if(pair.second>maxFreq){
                    maxFreq=pair.second;
                    ele=pair.first;
                }
            }
            for(int i=0;i<maxFreq;i++){
                res+=ele;
            }
            hm.erase(ele);
        }
        
        return res;
    }
};