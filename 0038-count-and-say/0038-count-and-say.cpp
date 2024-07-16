class Solution {
public:

    string fun(string ans){

        int n=ans.size();

        string temp="";
        int freq[10]={0};

        for(char c:ans){
            freq[c-'0']++;
        }

        int l=0;
        int r=0;

        while(r<n){

            while(r<n && ans[r]==ans[l]) r++;

            temp+=( to_string(r-l) );
            temp.push_back(ans[l]);
            l=r;
            

        }

        return temp;



    }
    string countAndSay(int n) {

        if(n==1) return "1";

        string ans="1";

        for(int i=2;i<=n;i++){
            string temp= fun(ans);
           

            ans=temp;
        }

        return ans;
        
    }
};