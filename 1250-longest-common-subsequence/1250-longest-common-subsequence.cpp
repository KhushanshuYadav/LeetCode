class Solution {

    //return length of LCS for sub string as text1[0...i1-1] && text2[0...i2-1]
    //i.e for strings with lenght i1 and i2
    
    int solve(int i1,int i2,string& text1, string& text2,vector<vector<int>>&dp){

        if(i1<=0 || i2<=0) return 0;  //no length to pick so lcs length will be zero


        if(dp[i1][i2]!=-1) return dp[i1][i2];



        //if current chars matches so include it in length i.e +1 and go deep
        if(text1[i1-1]==text2[i2-1]){

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

        //TABULATION
        //return solve(n1,n2,text1,text2,dp);

        vector<vector<int>>dp(n1+1,vector<int>(n2+1,-1));

        //each cell i,j stores LCS length for s1 and s2 's length as i and j i.e substr length of s1 and s2 i and j

        //filling base cases

        for(int col=0;col<=n2;col++){

            //for length of s1 as zero lcs will be zero as not chars to match
            dp[0][col]=0;
        }

        for(int row=0;row<=n1;row++){

            //for length of s2 as zero lcs will be zero as not chars to match
            dp[row][0]=0;
        }

        for(int i=1;i<=n1;i++){

            for(int j=1;j<=n2;j++){

                int ans=0;

                if(text1[i-1]==text2[j-1]){
                    ans=1+dp[i-1][j-1];
                }

                else{

                    int temp1=0+dp[i-1][j];
                    int temp2=0+dp[i][j-1];

                    ans=max(temp1,temp2);
                }

                dp[i][j]=ans;

                
            }
        }

        return dp[n1][n2];

        
    }
};