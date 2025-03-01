class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int n=nums.size();
        int f=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=0) {
                nums[f]=nums[i];
                f++;
            }

        }
        
        while(f<n){
            nums[f]=0;
            f++;
        }

        

      

        
    }
};