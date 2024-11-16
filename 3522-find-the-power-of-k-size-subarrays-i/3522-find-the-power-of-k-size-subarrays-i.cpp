class Solution {
private:
    bool fun(int i,int j,vector<int>&nums){
        for(int k=i;k<j;k++){

            if(nums[k+1]!=nums[k]+1) return false;
        }

        return true;
    }

    int findMax(int i,int j,vector<int>&nums ){
        int ans=INT_MIN;
        for(int k=i;k<=j;k++){

            ans=max(ans,nums[k]);
        }

        return ans;
    }
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        if(k==1) return nums;

        vector<int>ans;


        int n=nums.size();

        int left=0;
        int right=k-1;

        while(right<n){

            bool isSorted=fun(left,right,nums);

            if(isSorted){

                int mx=findMax(left,right,nums);
                ans.push_back(mx);

            }

            else{
                ans.push_back(-1);
            }

           



            right++;
            left++;
        }

        return ans;
        
    }
};