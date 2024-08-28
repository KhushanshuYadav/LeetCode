class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {

        int n=nums.size();

        vector<int>dp1(n,1);
        vector<int>dp2(n,1);

        for( int i=0;i<n;i++ ){

            for( int pI=0;pI<i;pI++ ){

                if( nums[pI]<nums[i] ) dp1[i]=max(dp1[i],dp1[pI]+1);
            }
        }

        for( int i=n-1;i>=0;i-- ){

            for( int nI=n-1;nI>i;nI-- ){

                if( nums[nI]<nums[i] ) dp2[i]=max(dp2[i],dp2[nI]+1);
            }
        }

        int ans=0;

        for( int i=0;i<n;i++ ){

            if(dp1[i]>1 && dp2[i]>1) ans=max(ans,dp1[i]+dp2[i]-1);
            
        }

        return n-ans;

        
    }
};