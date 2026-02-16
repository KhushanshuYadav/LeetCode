class Solution {
public:
    int reverseBits(int n) {

        int ans=0;
        int c=32;

        while(c--){

            ans<<=1;

            if(n&1) ans|=1;
            else ans|=0;

            n>>=1;
            
        }

        return ans;
        
    }
};