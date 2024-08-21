class Solution {

    //returns min operations count to convert s1[i..n1] to s2[j..n2] where n1 and n2 are lengths

    int solve(int i,int j,string& word1,string& word2,vector<vector<int>>&dp){

        //both bases cases will return zero if both s1 abd s2 are exhausted 

        
        if(i>word1.size()){

            
            //s1 exhausted need n2-j insertion if j exist including j th char
            //+1 to include j-1 th char
            return word2.size()-j+1;
        }

        if(j>word2.size()){
            //s2 exhausted need n1-i deletions if i exist including i th char
            //+1 to include i-1 th char
            return word1.size()-i+1;
        }

        if(dp[i][j]!=-1) return dp[i][j];




        if( word1[i-1]==word2[j-1] ){
            //if matches so no operation just move forward including 

            return(dp[i][j]= 0+solve(i+1,j+1,word1,word2,dp) );
        }

        else{
            //now we have option to insert, delete, replace the i th char of s1 so explore all and take min

            //inertion at i-1 position hypothetically as we have checked all prevs
            int insert=1+solve(i,j+1,word1,word2,dp);  

            //deletion of i th index
            int del= 1+solve(i+1,j,word1,word2,dp);

            //replace of i th with j th 
            int replace=1+solve(i+1,j+1,word1,word2,dp);


            return (dp[i][j]=  min({insert,del,replace}) );
        }
    }
public:
    int minDistance(string word1, string word2) {

        int n1=word1.size();
        int n2=word2.size();

        vector<vector<int>>dp(n1+1,vector<int>(n2+1,-1));

        return solve(1,1,word1,word2,dp);


        
    }
};