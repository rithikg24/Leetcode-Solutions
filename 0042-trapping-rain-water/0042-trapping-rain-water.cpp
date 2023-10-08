class Solution {
public:
    int trap(vector<int>& height) {
        // finding left max
        int leftMax[height.size()];
        int rightMax[height.size()];
        int lm=-1;
        for(int i=0;i<height.size();i++){
            if(lm<=height[i]){
                leftMax[i]=-1;
                lm=height[i];
            }else{
                leftMax[i]=lm;
            }
        }

        //finding right max
        int rm=-1;
        for(int i=height.size()-1;i>=0;i--){
            if(rm<=height[i]){
                rightMax[i]=-1;
                rm=height[i];
            }else{
                rightMax[i]=rm;
            }
        }
        int cnt=0;
        for(int i=0;i<height.size();i++){
            if(rightMax[i]!=-1 && leftMax[i]!=-1){
                cnt+=(min(leftMax[i],rightMax[i])-height[i]);
            }
        }

        return cnt;
    }
};