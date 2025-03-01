class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {

        int n=nums.size();

        int lastNonZero;
        vector<int>ans(n,-1);

        int f=0;
        int b=n-1;

        for(int i=0;i<n-1;){

            if(nums[i]!=0){

                if(nums[i]==nums[i+1]){
                    ans[f]=nums[i]*2;
                    f++;
                    ans[b]=0;
                    b--;

                    i+=2;
                }

                else{
                    ans[f]=nums[i];
                    f++;
                    i++;
                }
            }
            else{

                ans[b]=0;
                b--;
                i++;

            }

            
        }

        if(nums[n-2]==0){
            if(nums[n-1]==0) ans[b]=0;
            else ans[f]=nums[n-1];
        }
        else{
            if(nums[n-2]!=nums[n-1]){
                if(nums[n-1]==0) ans[b]=0;
                else ans[f]=nums[n-1];

            }
        }



        

        
        

        return ans;
        
    }
};