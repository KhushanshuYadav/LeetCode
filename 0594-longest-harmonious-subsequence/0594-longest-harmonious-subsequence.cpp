class Solution {
public:
    int findLHS(vector<int>& nums) {

        int n=nums.size();

        sort(nums.begin(),nums.end());

        unordered_map<int,int>m; //freq;

        int ans=0;

        for(int&i:nums) m[i]++;

        

        for(int i=1;i<n;i++){

            cout<<"i"<<i<<endl;

            if(nums[i]-nums[i-1]==1) {ans=max(ans,m[nums[i]]+m[nums[i-1]]); cout<<"ans"<<ans<<endl;}

            //m[nums[i]]++;

        }

        return ans;


        
    }
};