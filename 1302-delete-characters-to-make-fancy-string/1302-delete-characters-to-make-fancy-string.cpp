class Solution {
public:
    string makeFancyString(string s) {

        int l=0;
        int r=0;

        int n=s.size();

        string ans="";

        while(r<=n){

            if(s[r]!=s[l]){

                if((r-l)>=2){
                    ans.push_back(s[l]);
                    ans.push_back(s[l]);
                }
                else{
                    ans.push_back(s[l]);
                }
                
                l=r;

            }

            r++;

            
        }

        return ans;
        
    }
};