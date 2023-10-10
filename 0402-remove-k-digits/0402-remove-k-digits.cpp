class Solution {
public:
    
    string removeKdigits(string num, int k) {
        if(num.length()==k){
            return "0";
        }
        stack<char> s;
        int p=0;
        for(char x:num){
            while(p<k && !s.empty() && s.top()>x){
                s.pop();
                p++;
            }
            
            s.push(x);
            if(s.size()==1 && x=='0'){
                s.pop();
            }
        }
        while(p<k && !s.empty()){
            s.pop();
            p++;
        }
        string res="";
        while(!s.empty()){
            res+=s.top();
            s.pop();
        }
        if(res.size()==0){
            return "0";
        }
        reverse(res.begin(),res.end());
        
        
        return res;

    }
};