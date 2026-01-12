class Solution {

    void solve(int begin,int k,int n,vector<int>temp,vector<vector<int>>&ans){

        if(n<0) return;

        if(k==0 && n==0){
            ans.push_back(temp);
            return;
        }

        if(k==0 && n<0) return;

        if(k<0) return;

        for(int i=begin;i<=9;i++){

            
            temp.push_back(i);
            solve(i+1,k-1,n-i,temp,ans);
            temp.pop_back();
            
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<vector<int>>ans;

        vector<int>temp;

        solve(1, k, n,temp,ans);

        return ans;
    }
};