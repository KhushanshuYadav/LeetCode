class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {


        int n=nums.size();

        vector<int>ans;
        
        vector<int>dp(n,1);
        //stores length of longest divisible sub-seq ending at i th index i.e nums[j]%nums[i]==0 for each j>i;

        vector<int>prevIndex(n);   //our hash array
        //stores prevIndex of i th in LDS ending at i th index

        sort(nums.begin(),nums.end());

        

        
        int maxLen=1;
        int lastIndex=0;

        for(int i=0;i<n;i++){

            prevIndex[i]=i;

            for(int pI=0;pI<i;pI++){

                if( (nums[i]%nums[pI]==0) && (dp[pI]+1>dp[i]) ){
                    dp[i]=dp[pI]+1;
                    prevIndex[i]=pI;
                }

                if(dp[i]>maxLen){
                    lastIndex=i;
                    maxLen=dp[i];
                }

            }
        }

        ans.push_back(nums[lastIndex]);

        while(prevIndex[lastIndex]!=lastIndex){

            lastIndex=prevIndex[lastIndex];
            ans.push_back(nums[lastIndex]);
        }

        //reverse(ans.begin(),ans.end());

        return ans;

        
        
    }
};