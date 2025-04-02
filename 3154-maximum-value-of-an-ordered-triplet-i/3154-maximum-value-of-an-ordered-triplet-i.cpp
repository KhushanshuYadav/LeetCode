class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {

        int n=nums.size();
        long long ans=0;

        for(int i=0;i<n;i++){
            int j=i+1;
            int k=j+1;

            long long maxDiff=0;

            while(k<n){
                long long diff=nums[i]-nums[j];
                maxDiff=max(maxDiff,diff);

                long long val=maxDiff*nums[k];
                ans=max(ans,val);
                j++;
                k++;
            }
        }
        return (ans);


        
    }
};