class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_map<string,int> hm;

        for(string s:dictionary){
            hm[s]++;
        }

        string t="";
        string res="";
        int i;
        for(i=0;i<sentence.length();i++){
            char x=sentence[i];
            if(x==' '){
                res+=t;
                t="";
                res+=" ";
            }else{
                t+=x;
                if(hm.count(t)){
                    res+=t;
                    res+=" ";
                    t="";
                    i++;
                    while(i<sentence.length() && sentence[i]!=' '){
                        i++;
                    }
                }
            }
        }
        if(t!=""){
            res+=t;
        }else{
            res.pop_back();
        }
        
        return res;
    }
};