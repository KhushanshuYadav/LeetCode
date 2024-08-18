class Solution {
    //return length of LCS for sub string as text1[0...i1] && text2[0...i2]
    //i.e for strings ending at index i1 and i2
    
    int solve(int i1,int i2,string& text1, string& text2,vector<vector<int>>&dp){

        if(i1<0 || i2<0) return 0;  //no index to pick so lcs length will be zero


        if(dp[i1][i2]!=-1) return dp[i1][i2];



        //if current chars matches so include it in length i.e +1 and go deep
        if(text1[i1]==text2[i2]){

          return ( dp[i1][i2] = 1+solve(i1-1,i2-1,text1,text2,dp) );

        }

        else{

            //exploring all paths i.e not matched of t1 and can match with any in future of t2
            //or
            //not matched of t2 and can match with any in future of t1

            //so exploring both ways and retruning max between them
             
            int len1=0+solve(i1-1,i2,text1,text2,dp);
            int len2=0+solve(i1,i2-1,text1,text2,dp);

            return ( dp[i1][i2] =max(len1,len2) );
            
        }

    }
public:
    int longestCommonSubsequence(string text1, string text2) {

        int n1=text1.size();
        int n2=text2.size();

        vector<vector<int>>dp(n1,vector<int>(n2,-1));

        return solve(n1-1,n2-1,text1,text2,dp);
        
    }
};