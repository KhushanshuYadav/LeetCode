class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {

        int n=nums.size();

        int lastNonZero;
        vector<int>ans;

        for(int i=0;i<n-1;i++){

            if(nums[i]==nums[i+1]){
                nums[i]*=2;
                nums[i+1]=0;
            }

            if(nums[i]!=0) ans.push_back(nums[i]);
        }

        if(nums[n-1]!=0) ans.push_back(nums[n-1]);



        

        // if(nums[n-1]!=0) lastNonZero=n-1;

        // for(int i=0;i<n;i++){

        //     if(nums[i]==0){
        //         swap(nums[i],nums[lastNonZero]);
        //     }

        //     for(int j=lastNonZero-1;j>=0;j--){
        //         if(nums[j]!=0) {
        //             lastNonZero=j;
        //             break;
        //         }
        //     }

        // }

        for(int&i:nums){
            if(i==0) ans.push_back(i);
        }

        return ans;
        
    }
};