class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {

        int n=nums.size();

        vector<int>dp(n,1);

        vector<int>count(n,1);
        //stores count of 1.LIS of length dp[i] and 2.the last element of LIS is nums[i]

        int maxLen=1;
        for(int i=0;i<n;i++){

            for(int pI=0;pI<i;pI++){

                if( nums[pI]<nums[i] && dp[pI]+1>dp[i] ){

                    dp[i]=dp[pI]+1;

                    //as current element becomes part of an existing lis so count of lis ending with i th == count of lis ended with pI th
                    count[i]=count[pI];

                    maxLen=max(maxLen,dp[i]);
                }

                else if(dp[pI]+1==dp[i]){

                    //if we got lenght equals to maxLen again so inc the count cumilatvaley as nums[i] is part of now multiple lis's
                    count[i]+=count[pI];
                }
            }
        }


        int ans=0;
        for(int i=0;i<n;i++){

            if(dp[i]==maxLen){
                ans+=count[i];
            }

        }

        return ans;
        




        
    }
};