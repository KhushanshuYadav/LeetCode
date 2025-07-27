class Solution {
public:
    int countHillValley(vector<int>& nums) {

        int n=nums.size();

        int ans=0;

        for(int i=1;i<n;i++){

            if(nums[i]==nums[i-1]) continue;

            int prev=-1;
            for(int j=i;j>=0;j--){

                if(nums[j]!=nums[i]){
                    prev=j;
                    break;
                }

            }

            int next=-1;
            for(int j=i;j<n;j++){

                if(nums[j]!=nums[i]){
                    next=j;
                    break;
                }

            }

            if(prev!=-1 && next!=-1){
                if( (nums[prev]<nums[i] && nums[next]<nums[i]) || (nums[prev]>nums[i] && nums[next]>nums[i]) ) ans++;
            }
        }

        return ans;
        
    }
};