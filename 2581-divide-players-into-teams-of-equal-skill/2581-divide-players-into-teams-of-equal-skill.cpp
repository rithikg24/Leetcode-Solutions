class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());

        vector<pair<int,int>> p;
        int i=1;
        p.push_back({skill[0],skill[skill.size()-1]});
        int tot=skill[0]+skill[skill.size()-1];
        while(i<skill.size()/2){
            if(skill[i]+skill[skill.size()-i-1]!=tot){
                return -1;
            }else{
                p.push_back({skill[i],skill[skill.size()-i-1]});
            }
            i++;
        }
        long long chem=0;

        for(auto x:p){
            chem+=(x.first*x.second);
        }

        return chem;
    }
};