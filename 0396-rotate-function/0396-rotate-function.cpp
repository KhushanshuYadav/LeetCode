class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {

        int n=nums.size();

        int ans=0;

        int f=0; //for k==0
        int sum=0;
        for(int i=0;i<n;i++) {

            sum+=nums[i];
            f+=(i*nums[i]);
        }

        ans=f;


        for(int i=n-1;i>=1;i--){
            f=f+(sum-nums[i])-((n-1)*nums[i]);
            ans=max(f,ans);
        }
        
        return ans;
        
    }
};