class Solution {
     bool isVowel(char& c){
        return (c=='A' || c=='E' || c=='I' ||c=='O' || c=='U' ||c=='a'|| c=='e'|| c=='i'||c=='o'||c=='u');
    }
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {

        vector<string>ans;

        unordered_set<string>s(wordlist.begin(),wordlist.end());

        unordered_map<string,string>m1;

        unordered_map<string,string>m2;

        for(string& w:wordlist){

            string wC=w;
            transform(wC.begin(),wC.end(),wC.begin(),::tolower);

            if(!m1.count(wC)) m1[wC]=w;

            for(char&c:wC){
                if(isVowel(c)) c='*';
            }

            if(!m2.count(wC)) m2[wC]=w;

        }

        for(string&q:queries){

            if(s.count(q)) {
                ans.push_back(q);
                continue;
            }

            string wC=q;
            transform(wC.begin(),wC.end(),wC.begin(),::tolower);

            if(m1.count(wC)) {
                ans.push_back(m1[wC]);
                continue;
            }

            for(char&c:wC){
                if(isVowel(c)) c='*';
            }

            if(m2.count(wC)) {
                ans.push_back(m2[wC]);
                continue;
            }

            ans.push_back("");


        }

        return ans;
        
    }
};