class Solution {
public:
    void fun(int begin,int sum,int target,vector<int>&temp,vector<vector<int>>&ans,vector<int>& candidates){

        if(sum>target) return;
        if(sum==target){
            ans.push_back(temp);
            return;
        }

        for(int i=begin;i<candidates.size();i++){


            if(i!=begin && candidates[i]==candidates[i-1]) continue;

           
            
            
            temp.push_back(candidates[i]);
            sum+=candidates[i];
            fun(i+1,sum,target,temp,ans,candidates);
            temp.pop_back();
            sum-=candidates[i];
           
            
        

        }

        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        
        int begin=0;
        int sum=0;
        vector<int>temp;

        fun(begin,sum,target,temp,ans,candidates);
        
        return ans;
    }
};