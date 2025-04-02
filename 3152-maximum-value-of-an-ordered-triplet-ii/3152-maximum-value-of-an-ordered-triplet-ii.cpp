class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size();
        long long ans=0;
        long long maxDiff=0;
        long long maxVal=nums[0];
        int j=2;

        for(int i=1;j<n;i++){
            
            maxDiff=max(maxDiff,maxVal-nums[i]);
            ans=max(ans,(long long)maxDiff*nums[j]);
            maxVal=max(maxVal,(long long)nums[i]);
            j++;
            
        }
        return (ans);
        
    }
};