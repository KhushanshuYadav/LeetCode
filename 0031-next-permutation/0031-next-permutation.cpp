class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int breakPointIndex=-1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                breakPointIndex=i;
                break;
            }
        }

        if(breakPointIndex==-1) reverse(nums.begin(),nums.end());
        else{
            for(int i=n-1;i>breakPointIndex;i--){
                if(nums[i]>nums[breakPointIndex]) {swap(nums[i],nums[breakPointIndex]);break;}
            }
            reverse(nums.begin()+breakPointIndex+1,nums.end());
           
        }
       
    }
};