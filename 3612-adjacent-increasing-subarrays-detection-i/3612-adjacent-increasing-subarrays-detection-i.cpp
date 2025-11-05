class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        
        int n=nums.size();

        for(int i=0;i<=n-k-k;i++){

            bool isI1=true;
            for(int j=i+1;j<i+k;j++){
                if(nums[j]<=nums[j-1]){
                    isI1=false;
                    break;
                }
            }

            if(!isI1) continue;

            bool isI2=true;
            for(int j=i+k+1;j<i+k+k;j++){
                if(nums[j]<=nums[j-1]){
                    isI2=false;
                    break;
                }
            }

            if(isI1 && isI2) return true;


        }

        return false;
    }
};