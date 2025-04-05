class Solution {
    
public:
    int subsetXORSum(vector<int>& nums) {

        int orr=0;
        for(int& i:nums){
            orr|=i;
        }

        int ans=orr<<(nums.size()-1);

        
        return ans;
        
    }
};