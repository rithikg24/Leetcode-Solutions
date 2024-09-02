class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long tot=0;
        for(int i=0;i<chalk.size();i++){
            tot+=chalk[i];

        }
        int newK = k%tot;
        if(k<=tot) newK=k;
        for(int i=0;i<chalk.size();i++){
            if(newK<chalk[i]) return i;
            newK-=chalk[i];
        }
        return 0;
    }
};