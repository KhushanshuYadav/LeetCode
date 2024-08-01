class Solution {
public:
    int maximumLength(vector<int>& nums) {

        int n=nums.size();

        int evenCount=0;
        int oddCount=0;
        int bothCount=1;

        bool isFirstOdd=false;

        if(nums[0]%2==1){
            isFirstOdd=true;
        }
        
        for(int i=0;i<n;i++){

            if(nums[i]%2==0) evenCount++;

            else if(nums[i]%2!=0) oddCount++;

            if(i>0 && isFirstOdd && nums[i]%2==0) {
                bothCount++;
                isFirstOdd=false;
                
            }

            else if(i>0 && !isFirstOdd && nums[i]%2==1) {
                bothCount++;
                isFirstOdd=true;
                
            }


            

            

        }

        int ans=max({evenCount,oddCount,bothCount});
        return ans;
    }
};