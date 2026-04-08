class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {

        int mod=1e9+7;

        int ans=0;
        
        for(auto&q:queries) for(int i=q[0];i<=q[1];i+=q[2]) nums[i]=(1LL*nums[i]*q[3])%mod;

        for(int&i:nums) ans^=i;
            
        

        return ans;
    }
};