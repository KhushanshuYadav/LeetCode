class Solution {
public:
    bool isPalindrome(string s) {

        int n=s.size();

        // int i=0;
        // int j=n-1;

        string temp="";

        for(char& c:s){

            if(isalnum(c)) temp.push_back(tolower(c));
        }

        int i=0;
        int j=temp.size()-1;
        while(i<j){
            if(temp[i]!=temp[j]) return false;
            i++;
            j--;
        }

        return true;
    }
};