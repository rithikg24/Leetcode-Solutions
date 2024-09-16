class Solution {
public:
    int timeDiff(string st,string nt){
        int sthr = stoi(st.substr(0,2));
        int stmin = stoi(st.substr(3,2));
        int nthr = stoi(nt.substr(0,2));
        int ntmin = stoi(nt.substr(3,2));
        int tot = (nthr-sthr)*60+(60-stmin+ntmin);
        return tot;
    }
    string getNewTime(string ft){
        int hr = stoi(ft.substr(0,2));
        hr+=24;
        return to_string(hr)+ft.substr(2,3);
    }
    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(),timePoints.end());
        int res=INT_MAX;
        string nft = getNewTime(timePoints[0]);
        cout<<nft<<endl;
        timePoints.push_back(nft);
        for(int i=0;i<timePoints.size()-1;i++){
            string st = timePoints[i];
            string nt = timePoints[i+1];
            res=min(res,timeDiff(st,nt));
        }
        return res-60;
    }
};