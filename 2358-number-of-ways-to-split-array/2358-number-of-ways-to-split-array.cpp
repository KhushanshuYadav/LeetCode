class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {


        int n=nums.size();
        int ans=0;

        //vector<long >pS(n,0);

        long sum=0;
        for(int i=0;i<n;i++){

            sum+=nums[i];

        }

        long leftSum=0;
        for(int i=0;i<n-1;i++){

            leftSum+=nums[i];
            long rightSum=sum-leftSum;

            if(leftSum>=rightSum) ans++;
        }
        
        return ans;
    }
};