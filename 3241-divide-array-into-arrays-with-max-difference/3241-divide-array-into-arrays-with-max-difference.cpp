class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {

        int n=nums.size();

        sort(nums.begin(),nums.end());

        if(n==1 || n==2) return {};

        for(int i=2;i<n;i=i+3){

            if((nums[i]-nums[i-2])>k) return {};



        }

        vector<vector<int>>ans;

        for(int i=0;i<n;i=i+3){

            vector<int>v;
            for(int j=i;j<i+3;j++){
                v.push_back(nums[j]);
                
            }

            ans.push_back(v);
        }

        return ans;

        
    }
};