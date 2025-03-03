class Solution {

public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();

        vector<int>ans(n,pivot);
        int s=0;
        int e=n-1;

        for(int i=0, j=n-1;i<n;i++,j--){
            if(nums[i]<pivot){
                ans[s]=nums[i];
                s++;

            }
            if(nums[j]>pivot){
                ans[e]=nums[j];
                e--;

            }
        }

        return ans;
       
    }
};