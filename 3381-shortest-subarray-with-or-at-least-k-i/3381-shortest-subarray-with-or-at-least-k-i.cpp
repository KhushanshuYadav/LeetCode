class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {

        int n =nums.size();

        int ans=INT_MAX;

        for(int i=0;i<n;i++){

            int orr=0;

            for(int j=i;j<n;j++){

                orr=(orr | nums[j]);

                if(orr>=k) ans=min(ans,j-i+1);
            }
        }

        return ans==INT_MAX?-1:ans;
        
    }
};