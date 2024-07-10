class Solution {
public:
    int minOperations(vector<string>& logs) {
        int steps=0;
        for(string s:logs){
            if(s=="./"){
                continue;
            }else if(s=="../"){
                if(steps!=0){
                    steps--;
                }
            }else{
                steps++;
            }
        }

        return steps;
    }
};