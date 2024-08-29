class Solution {
public:
    void fun(int begin,vector<int>& nums,vector<vector<int>>&ans){
        if(begin==nums.size()-1){
            ans.push_back(nums);
            return;
        }

        for(int i=begin;i<nums.size();i++){  //we fix each i at begin position
            swap(nums[begin],nums[i]); //swap i.e fix ith and begin
            fun(begin+1,nums,ans);     //call for next not fixed half
            swap(nums[begin],nums[i]); //backtrack
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;

        fun(0,nums,ans);
        //begin == fixing position

        return ans;
    }
};