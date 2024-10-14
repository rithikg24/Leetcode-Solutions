class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(int x:nums){
            pq.push(x);
        }
        long long score=0;

        while(!pq.empty() && k--){
            int x=pq.top();
            pq.pop();
            score+=x;
            pq.push(ceil(x/3.0));
        }

        return score;
    }
};