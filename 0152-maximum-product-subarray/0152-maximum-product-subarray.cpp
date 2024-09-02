class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int n=nums.size();

        int maxP=INT_MIN;

        //product till i from start and last
        int pre=1;
        int suff=1;
        for(int i=0;i<n;i++){

            if(pre==0) pre=1;  //for carrying forward purpose

            if(suff==0) suff=1; //for carrying forward purpose

            pre=pre*nums[i];
            suff=suff*nums[n-i-1];

            maxP=max({maxP,pre,suff}); //ans can be current max of pre or suff

        }


        return maxP;
        
    }
};