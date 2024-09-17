class Solution {
    void fillMap(string s, unordered_map<string,int>& m){

        int n=s.size();
        string word="";
        for(int i=0;i<n;i++){

            if(s[i]==' '){
                m[word]+=1;
                word="";
                
            }
            else{
                word.push_back(s[i]);
            }

        }

        m[word]+=1;
        word="";

    }
public:
    vector<string> uncommonFromSentences(string s1, string s2) {

        unordered_map<string,int>m;

        

        fillMap(s1,m);
        fillMap(s2,m);

        vector<string>ans;

        for(auto& i:m){
            if(i.second==1) ans.push_back(i.first);
        }

        return ans;

        
    }
};