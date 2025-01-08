class Solution {

    bool isPrefixAndSuffix(string& s1,string& s2){
        // bool isPre=true;
        // bool isSuf=true;

       
        for(int i=0;i<s1.size();i++){

            if(s1[i]!=s2[i]) return false;

        }

        int j=s2.size()-1;
        for(int i=s1.size()-1;i>=0;i--){

            if(s1[i]!=s2[j]) return false;
            j--;

        }

        return true;


    }

public:
    int countPrefixSuffixPairs(vector<string>& words) {

        int n =words.size();

        int ans=0;

        for(int i=0;i<n;i++){

            for(int j=i+1;j<n;j++){

                string s1=words[i];
                string s2=words[j];

                if((s1.size()<=s2.size()) && (isPrefixAndSuffix(s1,s2)) ) ans++; 


            }
        }

        return ans;
        
    }
};