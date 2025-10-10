class Solution {

    int solve(int i,vector<int>& energy, int& k){

        cout<<"i "<<i<<endl;

        if(i>=energy.size()) return 0;

        int a1=energy[i]+solve(i+k,energy,k);

        cout<<"a1 "<<a1<<endl;

        int a2=0+solve(i+1,energy,k);

        cout<<"a2 "<<a2<<endl;

        return max(a1,a2);

    }
public:
    int maximumEnergy(vector<int>& energy, int k) {

        int n=energy.size();

        vector<int>dp=energy;

        int ans=INT_MIN;

        for(int i=n-1;i>=0;i--){

            if(i+k<n) {
                dp[i]=dp[i]+dp[i+k];
               
            }

            ans=max(ans,dp[i]);

           

           
        }

        return ans;

       
        
    }
};