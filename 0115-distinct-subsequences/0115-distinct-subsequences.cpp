class Solution {

    //returns count of distinct sub-seq in s[0..i] which are equal to s[0..j] where i and j are indexes
    int solve(int i,int j,string& s,string& t,vector<vector<int>>&dp){

        if(j<0) return 1;  // j gets exhausted i.e matched fully UNDERSTAND J IS MOVED WHEN IT IS MATCHED ONLY

        if(i<0) return 0;  //same as i<0 and j>=0 i.e j has some chars to match but i has nothing 

        if(dp[i][j]!=-1) return dp[i][j];




        if(s[i]==t[j]){
            int a1=solve(i-1,j-1,s,t,dp);

            int a2=solve(i-1,j,s,t,dp);

            return ( dp[i][j]=a1+a2 );
        }

        else{
            return ( dp[i][j]=solve(i-1,j,s,t,dp)) ;
        }

        

    }
public:
    int numDistinct(string s, string t) {

        int n1=s.size();
        int n2=t.size();

        vector<vector<int>>dp(n1,vector<int>(n2,-1));


        return solve(n1-1,n2-1,s,t,dp);

        


    }
};