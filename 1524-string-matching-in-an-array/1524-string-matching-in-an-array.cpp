class Solution {

    vector<int>giveLps(string& s){
        int n=s.size();
        vector<int>lps(n,0);

        for(int i =1;i<n;i++){

            int pI=lps[i-1];
            while(pI>0 && s[i]!=s[pI]){
                pI=lps[pI-1];
            }

            lps[i]=pI+(s[i]==s[pI]?1:0);

        }

        return lps;
    }

    bool kmp(string& pat,string& txt){
        int m=pat.size();
        int n=txt.size();

        auto lps=giveLps(pat);
        
        int j=0; //pattern
        int i=0; //txt
        

        while(i<n){

            if(pat[j]==txt[i]){
                i++;
                j++;
            }

            if(j==m){
                return true;
                j=lps[j-1];
            }

            else if(i<n && pat[j]!=txt[i]){

                if(j==0) i++;

                else j=lps[j-1];


            }
        }

        return false;
    }

    bool isSubStr(string& s1 ,string& s2){

        if(kmp(s1,s2)) return true;

        return false;
    }
public:
    vector<string> stringMatching(vector<string>& words) {

        int n=words.size();

        vector<string>ans;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){

                if(i!=j){

                    string s1=words[i];
                    string s2=words[j];

                    if( s1.size()<=s2.size() && isSubStr(s1,s2) ){
                        ans.push_back(s1);
                        break;
                    }

                }
            }
        }

        return ans;
        
    }
};