class Solution {
public:
    string makeFancyString(string s) {

        string ans;

        int n=s.size();
        int count=1;

        for(int i=0;i<n-1;i++){

            if(s[i]==s[i+1]){
                count++;
            }
            else{

                if(count>=2){
                    ans.push_back(s[i]);
                    ans.push_back(s[i]);
                    count=1;
                }

                else{
                    ans.push_back(s[i]);
                }
            }

            
        }

        if(count==1) ans.push_back(s[n-1]);
        else {
            ans.push_back(s[n-1]);
            ans.push_back(s[n-1]);
        }

        
        return ans;
        
    }
};