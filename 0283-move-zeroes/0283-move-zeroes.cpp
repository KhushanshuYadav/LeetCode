class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int n=nums.size();
        int zeroGrpSize=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0) {
                zeroGrpSize++;
            }
            else{
                swap(nums[i],nums[i-zeroGrpSize]);
            }

        }

        return;
        
        

        

      

        
    }
};