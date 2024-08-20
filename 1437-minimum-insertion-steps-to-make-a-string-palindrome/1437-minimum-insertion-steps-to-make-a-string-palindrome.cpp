class Solution {
private:
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
    int minInsertions(string s) {

        int n=s.size();

        string revS=s;
        reverse(revS.begin(),revS.end());

        int lcsLen=longestCommonSubsequence(s,revS);

        return n-lcsLen;        
    }
};