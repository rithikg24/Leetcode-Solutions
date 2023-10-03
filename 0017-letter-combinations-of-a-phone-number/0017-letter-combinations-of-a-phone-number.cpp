class Solution {
public:
    void helper(vector<string> &res,unordered_map<char,vector<char>> hm ,string digits,string temp,int i){
        if(i==digits.length() ){
            if(temp.length()==0){
                return;
            }
            res.push_back(temp);
            return;
        }

        for(char x:hm[digits[i]]){
            helper(res,hm,digits,temp+x,i+1);
        }
    }

    vector<string> letterCombinations(string digits) {
        unordered_map<char,vector<char>> mp;
        mp['2'] = {'a','b','c'} ;
        mp['3'] = {'d','e','f'};
        mp['4'] = {'g','h','i'};
        mp['5'] = {'j','k','l'};
        mp['6'] = {'m','n','o'};
        mp['7'] = {'p','q','r','s'};
        mp['8'] = {'t','u','v'};
        mp['9'] = {'w','x','y','z'};
        
        vector<string> res;
        helper(res,mp ,digits,"",0);
        return res;
        
    }
};