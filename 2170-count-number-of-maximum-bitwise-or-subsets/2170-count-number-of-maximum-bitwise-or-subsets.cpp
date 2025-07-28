class Solution {

    int solve(int i,int orr,int& maxOr,vector<int>& nums){

        if(i>=nums.size()){
            if(orr==maxOr) return 1;

            return 0;
        }

        return ( solve(i+1,orr|nums[i],maxOr,nums) + solve(i+1,orr,maxOr,nums) );
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {

        int maxOr=0;

        for(int&i:nums){
            maxOr|=i;
        }

        return solve(0,0,maxOr,nums);
        
    }
};