class Solution {
public:
    int rob(vector<int>& nums) {
        int n =nums.size();

        if(n==1) return nums[0];

        //SPACE optimization


        //LEAVE LAST ELEMENT 

        int ans1=0;

        int prev2_i=0; //dp[i-2]
        int prev1_i=nums[0];

        for(int i=1;i<n-1;i++){
            
            
            int curr=max(nums[i]+prev2_i,prev1_i);
            prev2_i=prev1_i;
            prev1_i=curr;
        } 
        ans1=prev1_i;




        //LEAVE FIRST ELEMENT 

        int ans2=0;

         prev2_i=0; //dp[i-2]
         prev1_i=nums[1];

        for(int i=2;i<n;i++){
            
            
            int curr=max(nums[i]+prev2_i,prev1_i);
            prev2_i=prev1_i;
            prev1_i=curr;
        } 
        ans2=prev1_i;



        return max(ans1,ans2);
        
    }
};