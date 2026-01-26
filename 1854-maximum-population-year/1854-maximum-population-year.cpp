class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {

        int n=logs.size();

        vector<vector<int>>ev;

        for(auto&l:logs){
            ev.push_back({l[0],+1});
            ev.push_back({l[1],-1});
        }

        sort(ev.begin(),ev.end(),[&](auto e1,auto e2){ return (e1[0]!=e2[0])?e1[0]<e2[0]:e1[1]<e2[1]; });

        int mnYear=-1;
        int mxPop=INT_MIN;
        int pop=0;
        
        for(auto&e:ev){
            pop+=e[1];

            if(pop>mxPop){
                mxPop=pop;
                mnYear=e[0];
            }
        }

        return mnYear;
        
    }
};