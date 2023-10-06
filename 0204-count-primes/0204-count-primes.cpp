class Solution {
public:
    int countPrimes(int n) {
        vector<int> arr(n,0);
        for(int i=2;i<n;i++){

            if(arr[i]==0){
                for(int j=2;i*j<n;j++){
                    arr[i*j]=1;
                }
            }
            // marking all multiples of i;
            
        }
        int cnt=0;
        for(int i=2;i<n;i++){
            if(!arr[i]) cnt++;
        }
        return cnt;
    }
};