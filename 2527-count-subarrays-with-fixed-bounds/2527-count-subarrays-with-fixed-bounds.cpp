class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {

        int n=nums.size();

        long long ans=0;

        int mnIdx=-1;
        int mxIdx=-1;
        int brkIdx=-1;

        for(int i=0;i<n;i++){

            if(nums[i]<minK || nums[i]>maxK) brkIdx=i;

            if(nums[i]==minK) mnIdx=i;

            if(nums[i]==maxK) mxIdx=i;

            int  count=max(0,min(mnIdx,mxIdx)-brkIdx);

            ans+=count;
        }

        return ans;


        
    }
};