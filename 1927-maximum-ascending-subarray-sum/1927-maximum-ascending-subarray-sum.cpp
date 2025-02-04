class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {

        int n=nums.size();
        int ans=nums[0];
        int sum=nums[0];
        //ans=max()
        for(int i=1;i<n;i++){

            ans=max(ans,nums[i]);

            if(nums[i]>nums[i-1]) sum+=nums[i];

            else sum=nums[i];

            ans=max(ans,sum);

        }

        return ans;
        
    }
};