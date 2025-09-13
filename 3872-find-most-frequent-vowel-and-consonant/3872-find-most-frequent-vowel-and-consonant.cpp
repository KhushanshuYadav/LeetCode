class Solution {

    bool isVowel(char&c){
        return (c=='a' || c=='e' || c=='i' || c=='o'|| c=='u');
    }
public:
    int maxFreqSum(string s) {

        int a=0;
        int b=0;

        vector<int>v(26,0);

        for(char&c:s){

            if(isVowel(c)) a=max(a,++v[c-'a']);

            else b=max(b,++v[c-'a']);

        }

        return a+b;
        
    }
};