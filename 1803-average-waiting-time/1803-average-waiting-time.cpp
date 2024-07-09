class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {

        int n=customers.size();
        int t=0;
        long long int sum=0;
        

        for(auto v:customers){

            if(t<v[0]){
                t+=abs(v[0]-t);

            }

            t+=abs(v[1]);
            sum+=abs( (long long int )(t-v[0]) ) ;



        }

        double ans=(double)sum/(double)n;
        return ans;
        
    }
};