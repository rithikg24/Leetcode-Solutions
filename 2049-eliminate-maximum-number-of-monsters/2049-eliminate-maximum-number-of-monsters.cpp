class Solution {
public:
    
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<int> timeTaken(dist.size(),0);
        for(int i=0;i<dist.size();i++){
            timeTaken[i]=ceil(dist[i] / (double)speed[i]);
        }

        sort(timeTaken.begin(),timeTaken.end());

        int time=0;
        for(int i=0;i<timeTaken.size();i++){
            if(time>=timeTaken[i]){
                return time;
            }
            time++;
        }
        return time;
    }
};