class Solution {
    bool solve(int start,vector<int>&ans,vector<int>&used,int n){

        if(start==ans.size()) return true;

        if(ans[start]!=0){
            //try for next index this is already filled
            return solve(start+1,ans,used,n);
        }

        for(int i=n;i>=1;i--){
            //try all possible values at this index
            if(used[i]) continue;


            used[i]=1;
            ans[start]=i;


            if(i==1){
                
                if( solve(start+1,ans,used,n)) return true;
            }

            else if(start+i<ans.size() && ans[start+i]==0){

                ans[start+i]=i;

                if( solve(start+1,ans,used,n)) return true;

                ans[start+i]=0;
            }

            ans[start]=0;
            used[i]=0;
        }

        return false;


    }
public:
    vector<int> constructDistancedSequence(int n) {

        vector<int>ans(2*n-1,0);
        vector<int>used(n+1,0);

        solve(0,ans,used,n);

        return ans;
        
    }
};