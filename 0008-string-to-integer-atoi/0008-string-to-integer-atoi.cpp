class Solution {
public:
    int myAtoi(string s) {
        bool isNeg=false;
        double res=0;
        int i=0;
        while(s[i]==' '){
            i++;
        }
        if(s[i]=='-') {
            isNeg=true;
            i++;
        }else if(s[i]=='+'){
            i++;
        }
        
        while((s[i]>='0' && s[i]<='9') && i<s.length()){
            int n=s[i]-'0';
            res=(res*10)+n;
            i++;
        }

        if(isNeg) res=-res;

        if(res>INT_MAX) return INT_MAX;
        if(res<INT_MIN) return INT_MIN;

        
        return res;
    
    }
};