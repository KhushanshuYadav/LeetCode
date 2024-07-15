class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>>ans;

        sort(nums.begin(),nums.end());
        

        int n=nums.size();
        for(int i=0;i<n;i++){
            //int sum=target-nums[a]-nums[b];

            if(i!=0 && nums[i]==nums[i-1])continue;
            int sum=-nums[i];

            int left=i+1;int right=n-1;
            
            while(left<right){
                if(nums[left]+nums[right]==sum){
                    ans.push_back( { nums[i],nums[left],nums[right] } );
                    left++;
                    right--;
                    while(left<right && nums[left]==nums[left-1]) left++;
                    while(left<right && nums[right]==nums[right+1]) right--;
                }

                else if(nums[left]+nums[right]>sum) right--;

                else left++;
            }
        }

        return ans;
    }
};