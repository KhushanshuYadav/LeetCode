class Solution {

    int mod=1000000007;
public:
    int numOfSubarrays(vector<int>& arr) {

        int n=arr.size();

        int pS=0;
        int oSum=0;
        int eSum=1;
        int ans=0;

        for(int i=0;i<n;i++){

            pS+=arr[i];

            if(pS&1){
                //if pS is odd
                ans+=eSum;
                oSum++;
            }

            else{
                //if pS is even
                ans+=oSum;
                eSum++;

            }

            ans=ans%mod;

        }

        return ans;
        
    }
};