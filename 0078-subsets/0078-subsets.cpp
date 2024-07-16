class Solution {
    public:
 void fun(int n,vector<int>& nums,vector<vector<int>>&ans,vector<int>&temp){


        if(n<0) {

            ans.push_back(temp);
            

            return;
        }

        


      


        temp.push_back(nums[n]);
        fun(n-1,nums,ans,temp);
        temp.pop_back();
        fun(n-1,nums,ans,temp);
        



    }
    vector<vector<int>> subsets(vector<int>& nums) {


        vector<vector<int>>ans;
        int n=nums.size();
        vector<int>temp;
        int i=0;
        
        fun(n-1,nums,ans,temp);


        return ans;
        
    }
};