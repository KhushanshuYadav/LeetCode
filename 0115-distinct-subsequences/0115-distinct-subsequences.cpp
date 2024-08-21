class Solution {

    //returns count of distinct sub-seq in s[0..i] which are equal to s[0..j] where i and j are LENGTHS
    int solve(int i,int j,string& s,string& t,vector<vector<int>>&dp){

        if(j<=0) return 1;  // j gets exhausted i.e matched fully UNDERSTAND J IS MOVED WHEN IT IS MATCHED ONLY

        if(i<=0) return 0;  //same as i<=0 and j>0 i.e j has some chars to match but i has nothing 

        if(dp[i][j]!=-1) return dp[i][j];




        if(s[i-1]==t[j-1]){
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
         
        //TABULATION;
        

        vector<vector<int>>dp(n1+1,vector<int>(n2+1,-1));
        //dp[i][j] stores count of distinct sub-seq in s[0..i] which are equal to t[0..j] where i and j are LENGTHS

        //filling base cases

        //j==0 i.e exhausted

        for(int row=0;row<=n1;row++){
            dp[row][0]=1;
        }

        for(int col=1;col<=n2;col++){
            dp[0][col]=0;
        }        
        
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){

                if(s[i-1]==t[j-1]){
                    int a1=dp[i-1][j-1];
                    int a2=dp[i-1][j];

                    dp[i][j]=(long )a1+a2;
                }

                else{

                    dp[i][j]=dp[i-1][j];
                }
            }
        }

        return dp[n1][n2];

    




        

        


    }
};