class Solution {
    void solve(int i,string temp,int& n,unordered_set<string>& dict,string& s, vector<string>&ans){

        if(i==n){
            ans.push_back(temp);
           
            return ;
        }



        for(int k=i;k<n;k++){

            string t=s.substr(i,k-i+1);

            if( dict.count(t) ){

                if(temp==""){
                    solve(k+1,temp+t,n,dict,s,ans);
                    //temp=temp+t;

                }

                else{
                    solve(k+1,temp+" "+t,n,dict,s,ans);
                    //temp=temp+" "+t;
                }

                //solve(k+1,temp,n,dict,s,ans);


            }
        }
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {

        int n=s.size();        
        unordered_set<string>dict(wordDict.begin(),wordDict.end());

        vector<string>ans;
        string temp="";

        solve(0,temp,n,dict,s,ans);

        return ans;

        
    }
};