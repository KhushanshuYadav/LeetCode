class Solution {
public:
    int minSwaps(vector<int>& nums) {

    

        int n=nums.size();

        if(n==1) return 0;

        //int maxCOnes=0;
        //int cOnes=0;
        int ones=0;
        int twoN=2*n;

        /*for(int i=0;i<twoN;i++){

            if(i>=N && nums[i%n]==1){

                cOnes++;
                maxCOnes=max(maxCOnes,cOnes);

            }

            else if(nums[i%n]==1){
                ones++;
                cOnes++;
                maxCOnes=max(maxCOnes,cOnes);
            }

            else{

                maxCOnes=max(maxCOnes,cOnes);
                cOnes=0;


                

            }



        }*/

        for(int &i:nums){
            if(i==1) ones++;
        }

        int winOnes=0;
        int ans=n;
        

        for(int i=0;i<ones;i++){
            if(nums[i%n]==1) winOnes++;
        }

        
        int temp=ones-winOnes;
        ans=min(ans,temp);
        for(int i=ones;i<twoN;i++){

            if(nums[(i-ones)%n]==1) winOnes--;

            if(nums[i%n]==1) winOnes++;

            int temp=ones-winOnes;

            ans=min(ans,temp);

        }
        
        

        return ans;
    }
};