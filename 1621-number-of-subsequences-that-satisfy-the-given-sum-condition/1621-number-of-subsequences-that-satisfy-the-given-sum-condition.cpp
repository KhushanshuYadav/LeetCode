class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {

        int n=nums.size();

        int MOD=1e9+7;

        int ans=0;

        vector<int>power(n,1);

        for(int i=1;i<n;i++){
            power[i]=(power[i-1]*2)%MOD;
        }

        sort(nums.begin(),nums.end());

        int left=0;
        int right=n-1;

        while(left<=right){
            if(nums[left]+nums[right]<=target){
                ans=(ans+power[right-left])%MOD;
                
                left++; //try for more

            }
            else right--; //now > target try to move below
        }

        return ans;


        
    }
};