class Solution {

    int longestCommonSubsequence(string text1, string text2) {

        int n1=text1.size();
        int n2=text2.size();

        //TABULATION SPACE OPTIMIZED
        //return solve(n1,n2,text1,text2,dp);

        vector<int>prevRow(n2+1,0);
        vector<int>currRow(n2+1,0);

        //each cell i,j stores LCS length for s1 and s2 's length as i and j i.e substr length of s1 and s2 i and j

        //filling base cases
        //set first row and col zero which are already zero

        

        for(int i=1;i<=n1;i++){

            for(int j=1;j<=n2;j++){

                int ans=0;

                if(text1[i-1]==text2[j-1]){
                    ans=1+prevRow[j-1];
                }

                else{

                    int temp1=0+prevRow[j];
                    int temp2=0+currRow[j-1];

                    ans=max(temp1,temp2);
                }

                currRow[j]=ans;

                
            }

            prevRow=currRow;
        }

        return prevRow[n2];

        
    }
public:
    int longestPalindromeSubseq(string s) {

        string s1=s;
        reverse(s1.begin(),s1.end());

        return longestCommonSubsequence(s,s1);
        
    }
};