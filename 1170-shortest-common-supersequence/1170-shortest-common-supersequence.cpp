class Solution {
    vector<vector<int>> longestCommonSubsequence(string& text1, string& text2) {

        int n1=text1.size();
        int n2=text2.size();

        

        vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));


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

        return dp;
        
    }
public:
    string shortestCommonSupersequence(string str1, string str2) {
        
        int n1=str1.size();
        int n2=str2.size();

        auto dp=longestCommonSubsequence(str1,str2);

        string ans="";

        int i=n1;
        int j=n2;

        while(i>0 && j>0){

            if(str1[i-1]==str2[j-1]){
                ans.push_back(str1[i-1]);
                //take the common portion one time only i.e part of lcs should be taken once
                i--;
                j--;
            }

            else if(dp[i-1][j]>dp[i][j-1]){

                ans.push_back(str1[i-1]);
                //we are loosing the i th of s1 as not equal (not part of lcs) so take it

                i--;

            }

            else{

                ans.push_back(str2[j-1]);


                j--;

            }
        }

        while(i>0)  {ans.push_back(str1[i-1]);i--;} //if(i>0)
        while(j>0)  {ans.push_back(str2[j-1]);j--;} //else


        reverse(ans.begin(),ans.end());//as we build from last

        return ans;



        
    }
};