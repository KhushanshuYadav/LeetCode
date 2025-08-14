class Solution {
public:
    string largestGoodInteger(string num) {

        int n=num.size();

        string ans;
        for(int i=0;i<=n-3;i++){
            
            if(num[i]==num[i+1] && num[i+1]==num[i+2]){

                if(ans.empty() || num[i]>=ans[0]) {
                    ans="";
                    for(int j=0;j<3;j++) {
                        ans.push_back(num[i]);
                    }
                }
            }
        }

        return ans;
    }
};