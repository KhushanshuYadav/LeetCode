class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {

        int n=rains.size();

        set<int>s;
        unordered_map<int,int>m; //lake,fullday

        vector<int>ans(n,1);

        

        for(int i=0;i<n;i++){

            if(rains[i]==0) s.insert(i);

            else if( rains[i] >0 ) {

                if(!m.count(rains[i])) {
                    m[rains[i]]=i;
                    ans[i]=-1;
                }

                else{

                    auto it=s.upper_bound(m[rains[i]]);

                    if(it!=s.end()){
                        ans[*it]=rains[i];
                        s.erase( *it );
                        ans[i]=-1;
                        m[rains[i]]=i;
                    }

                    else return {};
                }
                
            }


           

          
        }

        return ans;


        
    }
};