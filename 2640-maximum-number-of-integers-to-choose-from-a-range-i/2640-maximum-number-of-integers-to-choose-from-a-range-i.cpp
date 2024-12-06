class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        set<int> b(banned.begin(),banned.end());

        int sum=0;
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(b.find(i)==b.end()){
                if(sum+i>maxSum){
                    break;
                }else{
                    sum+=i;
                    cnt++;
                }
            }
        }
        return cnt;
    }
};