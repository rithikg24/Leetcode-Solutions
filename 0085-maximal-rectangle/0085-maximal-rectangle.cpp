class Solution {
public:
    vector<int> nextSmallerFunc(vector<int> a){
        int n = a.size();

        vector<int> res(n);
        stack<int> s;
        for(int i=n-1;i>=0;i--){
            if(s.empty()){
                res[i]=-1;
                s.push(i);
            }else{
                if(a[s.top()]<a[i]){
                    res[i]=s.top();
                    s.push(i);
                }else{
                    while(!s.empty() && a[s.top()]>a[i]){
                        s.pop();
                    }
                    if(s.empty()){
                        res[i]=-1;
                    }else{
                        res[i]=s.top();
                    }
                    s.push(i);
                }
            }
        }
        return res;
    }

    vector<int> prevSmallerFunc(vector<int> &heights){
        int n = heights.size();
        vector<int> prev(n);
        stack<int> st;
        st.push(-1);
        for(int i = 0; i < n; i++){
            while(st.top() != -1 && heights[st.top()] >= heights[i]){
                st.pop();
            }
            prev[i] = st.top();
            st.push(i);
        }
        return prev;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> nextSmaller;
        vector<int> prevSmaller;

        nextSmaller = nextSmallerFunc(heights);
        prevSmaller = prevSmallerFunc(heights);

        
    
        int maxArea=0;
        for(int i=0;i<n;i++){
            int l = heights[i];
            if(nextSmaller[i]==-1){
                nextSmaller[i]=n;
            }
            int b = nextSmaller[i]-prevSmaller[i]-1;
            int area = l*b;
            maxArea=max(area,maxArea);
        }
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxArea=0;

        vector<int> hs(matrix[0].size(),0);

        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j]=='1'){
                    hs[j]=hs[j]+1;
                }else{
                    hs[j]=0;
                }
            }

            int area = largestRectangleArea(hs);
            maxArea = max(area,maxArea);
        }

        return maxArea;
    }
};