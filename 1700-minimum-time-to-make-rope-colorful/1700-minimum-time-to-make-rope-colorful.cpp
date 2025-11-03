class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {

        int ans=0;
        int n=neededTime.size();

        int sum=0;
        int mx=0;

        for(int i=0;i<n;i++){

            sum+=neededTime[i];
            mx=max(mx,neededTime[i]);

            if(colors[i]!=colors[i+1]){

                ans+=(sum-mx);
                sum=0;
                mx=0;
            }
        }

        return ans;
        
    }
};