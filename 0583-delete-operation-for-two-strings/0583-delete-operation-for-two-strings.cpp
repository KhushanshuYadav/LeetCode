class Solution {
     int longestCommonSubsequence(string& s1,string& s2){

        int n1=s1.size();
        int n2=s2.size();

        vector<int>prevRow(n2+1,0);
        vector<int>currRow(n2+1,0);





        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(s1[i-1]==s2[j-1]){
                    currRow[j]=1+prevRow[j-1];
                }

                else{
                    currRow[j]=max(prevRow[j],currRow[j-1]);
                }
            }
            prevRow=currRow;
        }

        return prevRow[n2];
    }
public:
    int minDistance(string word1, string word2) {

        if(word1==word2) return 0;

        

        int n1=word1.size();
        int n2=word2.size();

        int lcsLen=longestCommonSubsequence(word1,word2);

        int ans1=n1-lcsLen;
        int ans2=n2-lcsLen;

        return ans1+ans2;
        
    }
};