class Solution {
    bool isVowel(char& c){
        return (c=='a' ||c=='e' ||c=='i' ||c=='o' ||c=='u');
    }
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {

        int n=words.size();
        vector<int>ans;
        vector<int>prefix(n,0);

        prefix[0]=( isVowel(words[0][0]) &&  isVowel(words[0][words[0].size()-1]) )?1:0;

        for(int i=1;i<n;i++){

            string word=words[i];
            char f=word[0];
            char l=word[word.size()-1];

            if(isVowel(f) && isVowel(l)) prefix[i]=prefix[i-1]+1;

            else prefix[i]=prefix[i-1];
        }



        for(auto query:queries){
            int s=query[0];
            int e=query[1];

            if(s==0) ans.push_back(prefix[e]);
            else ans.push_back(prefix[e]-prefix[s-1]);

            

            
            
        }

        return ans;
        
    }
};