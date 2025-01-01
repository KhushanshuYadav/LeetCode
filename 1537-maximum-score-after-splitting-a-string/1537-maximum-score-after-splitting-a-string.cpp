class Solution {
public:
    int maxScore(string s) {

        int ans=INT_MIN;
        int n =s.size();

        
        int totalOnes=0;
        for(char c:s){
            if(c=='1') totalOnes++;

            
        }

        int leftZeros=0;
    
        int rightOnes=totalOnes;
        for(int i=0;i<n-1;i++){

            if(s[i]=='0') leftZeros++;

            else {
                
                rightOnes--;
               

            }
            ans=max(ans,leftZeros+rightOnes);

            
        }

        

        return ans;
    }
};