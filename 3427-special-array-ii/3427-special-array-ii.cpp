class Solution {
public:

    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {

        vector<int>pS(1,0);

        int j=0;
        for(int i=0;i<nums.size()-1;i++){
            if( (nums[i]&1) == (nums[i+1]&1) ) j++;

            pS.push_back(j);
        }

        vector<bool>ans;

        for(auto q:queries) {
            ans.push_back( pS[q[0]]==pS[q[1]] );
        }

        return ans;

        
    }
};