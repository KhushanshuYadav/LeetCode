class Solution {
public:
    int numRabbits(vector<int>& answers) {

        int n=answers.size();
        int ans=0;

        unordered_map<int,int>m;

        for(int &i:answers){
            m[i]++;
        }

        for(auto&p:m){

            int grpSize=p.first+1;
            int saidR=p.second;

            int grps=ceil(saidR/(double)grpSize);

            ans+=(grps*grpSize);


        }

        return ans;

        
    }
};