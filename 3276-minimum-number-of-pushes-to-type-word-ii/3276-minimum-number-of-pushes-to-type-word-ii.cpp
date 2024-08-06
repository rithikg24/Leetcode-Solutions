class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char,int> hm;
        for(char c:word){
            hm[c]++;
        }
        if(hm.size()<=8){
            return word.length();
        }
        vector<int> freq;
        for(auto x:hm){
            freq.push_back(x.second);
        }
        sort(freq.begin(),freq.end());

        int res=0;
        for(int i=freq.size()-1;i>=0;i--){
            int mul=((freq.size()-1-i)/8)+1;
            res+=(mul*freq[i]);
        }
        
        return res;
    }
};