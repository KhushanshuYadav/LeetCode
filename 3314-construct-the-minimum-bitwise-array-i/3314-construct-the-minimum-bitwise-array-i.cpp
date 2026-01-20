class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {

        vector<int>ans(nums.size(),-1);

        for(int i=0;i<nums.size();i++){

            int temp=-1;
            for(int j=0;j<nums[i];j++){
                if( (j | (j+1) ) == nums[i]){
                    temp=j;
                    break;
                }
            }

            ans[i]=temp;
        }


        return ans;
        
    }
};