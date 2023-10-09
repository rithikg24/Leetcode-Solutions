class Solution {
public:
    int mod(int x){
        if(x<0) return 0-x;
        return x;
    }

    bool sameSign(int a,int b){
        if((a>0 && b>0) || (a<0 || b<0)) return true;
        return false;
    }

    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;

        for(int x:asteroids){
            if(s.empty()){
                s.push(x);
            }else if(s.top()>0 && x<0){
                int tmp = x;
                bool equal = false;
                while(!s.empty() && s.top()>0 && tmp<0){
                    int modX = mod(x);
                    int top = s.top();
                    s.pop();
                    int modTop = mod(top);
                    if(modX==modTop){
                        equal = true;
                        break;
                    }else if(modX<modTop){
                        tmp=top;
                    }
                }
                if(!equal){
                    s.push(tmp);
                }
            }else{
                s.push(x);
            }
            // }else if(sameSign(s.top(),x) == true){
            //     s.push(x);
            // }else{
            //     int tmp=x;
            //     bool equal = false;
            //     while(!s.empty() && !sameSign(s.top(),tmp)){
            //         int xMod = mod(tmp);
            //         int top = s.top();
            //         s.pop();
            //         int topMod = mod(top);
            //         if(topMod > xMod){
            //             tmp = top;
            //         }else if(topMod == xMod){
            //             equal = true;
            //             break;
            //         }
            //     }
            //     if(!equal){
            //         s.push(tmp);
            //     }
            // }
        }

        vector<int> res;
        while(!s.empty()){
            res.push_back(s.top());
            s.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};