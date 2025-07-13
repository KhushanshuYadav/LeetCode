class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {

        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());

        int n1=players.size();
        int n2=trainers.size();

        int j=0;

        int ans=0;

        for(int i=0;i<n1;){

            if(players[i]<=trainers[j]){
                ans++;
                i++;
                //j++;
            }

            j++;

            if(j>=n2) return ans;



        }

        return ans;

        
    }
};