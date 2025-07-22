class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {

        int n=nums.size();
        int l=0;
        int r=0;

        int ans=0;
        int sum=0;

        unordered_set<int>s;

        while(r<n){

            while(l<r && s.count(nums[r])){

                s.erase(nums[l]);
                sum-=nums[l];
                //cout<<"sum1 "<<sum<<endl;
                l++;

            }

            sum+=nums[r];
            s.insert(nums[r]);
           // cout<<"sum2 "<<sum<<endl;

            ans=max(ans,sum);
        // cout<<"ans "<<ans<<endl;

            r++;

        }

        return ans;

        
    }
};