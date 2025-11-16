class Solution {
public:
    int numSub(string s) {

        int mod=1e9+7;

        int streak=0;
        int ans=0;

        for(char& c:s){

            if(c=='1') {
                streak++;
                ans+=(streak);
                ans%=mod;
            }

            else streak=0;

           

        }
        
        return ans;
    }
};