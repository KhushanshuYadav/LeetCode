class Solution {

    bool solve(int start,string temp,unordered_set<string>s,int& n,string& ans){

        if(start==n){

            if(!s.count(temp)){
                ans=temp;
                return true;

            } 

            return false;

        }

        if(solve(start+1,temp+'0',s,n,ans)) return true ;

        if(solve(start+1,temp+'1',s,n,ans) ) return true ;

        return false;
    }
public:
    string findDifferentBinaryString(vector<string>& nums) {

        unordered_set<string>s(nums.begin(),nums.end());
        string ans="";

        int n=nums[0].size();

        solve(0,"",s,n,ans);

        return ans;

        
    }
};