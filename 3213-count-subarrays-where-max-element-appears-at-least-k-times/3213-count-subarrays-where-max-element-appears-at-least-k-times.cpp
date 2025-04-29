class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {

        int n=nums.size();

        int mx=INT_MIN;
        for(int&i:nums) mx=max(mx,i);

        long long ans=0;
        int l=0;
        int r=0;
        //int firstPos=INT_MAX;
        int freq=0;

       

        while(r<n){

            if(nums[r]==mx){
                freq++;
            }

            while(freq>=k){

                ans+=(n-r);

                if(nums[l]==mx) {
                    freq--;
                   
                }
                l++;

               

            }

            
            
            r++;


        }

        return ans;
        
    }
};