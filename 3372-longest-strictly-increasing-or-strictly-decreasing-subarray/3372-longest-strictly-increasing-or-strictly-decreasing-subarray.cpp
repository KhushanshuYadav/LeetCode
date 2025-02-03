class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {

        int n=nums.size();

        int ans=1;

        for(int i=0;i<n;i++){

            int ansI=1;

            for(int j=i+1;j<n;j++){

                if(nums[j]<=nums[j-1]) break;

                ansI++;

            }

            cout<<"I "<<ansI<<endl;

            int ansD=1;

            for(int j=i+1;j<n;j++){

                if(nums[j]>=nums[j-1]) break;

                ansD++;

            }

            cout<<"D "<<ansD<<endl;

            ans=max({ans,ansI,ansD});

           cout<<"A "<<ans<<endl;


        }

        return ans;
        
    }
};