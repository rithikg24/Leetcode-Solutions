class Solution {
public:

    bool func(vector<int> nums,int weight,int days){
        int ptr=0;
        int daysCnt=0;
        int s=0;
        while(ptr<nums.size() && daysCnt<days){
            if(daysCnt>=days){
                break;
            }
            if(s+nums[ptr]<=weight){
                s=s+nums[ptr];
                ptr++;
            }else{
                s=0;
                daysCnt++;
            }
        }
        if(daysCnt>=days){
            return false;
        }
        if(ptr!=nums.size()){
            return false;
        }
        return true;
    }

    int findMax(vector<int>nums){
        int maxNum=INT_MIN;
        for(int x:nums){
            maxNum=max(maxNum,x);
        }
        return maxNum;
    }

    int sumOf(vector<int>nums){
        int sum=0;
        for(int x:nums){
            sum+=x;
        }
        return sum;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int s=findMax(weights),e=sumOf(weights);

        while(s<=e){
            int m=(s+e)/2;
            bool a=func(weights,m,days);
            if(!a){
                s=m+1;
            }else{
                e=m-1;
            }
        }
        return s;
    }
};