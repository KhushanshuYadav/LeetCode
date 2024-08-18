class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {

        int n=nums.size();

        //max lenght at of subarray ending at  i th index by question constraints;

        vector<int>dp(n,1);
        vector<int>ans;

        dp[0]=1;

        for(int i=1;i<n;i++){

            if(nums[i]==nums[i-1]+1) dp[i]=dp[i-1]+1;  //follows question's constraints so inc the length;

            else dp[i]=1;                              //start new sub array
        }

        for(int i=k-1;i<n;i++){

            if(dp[i]>=k) ans.push_back(nums[i]);

            else ans.push_back(-1);
        }

        return ans;

        
    }
};