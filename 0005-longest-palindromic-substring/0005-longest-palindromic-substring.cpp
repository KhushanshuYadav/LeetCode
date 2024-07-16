class Solution {
public:
    string returnPallindrome(string&s,int left,int right){ 
        
         //it expands from centre
         int n=s.size();

        while(left>=0 && right<n){

            if(s[left]!=s[right]) break;

            left--;
            right++;
        }

        return s.substr(left+1,right-left-1);


    }

    void updateAns(string& newS,string&ans,int& maxLen){
        if(newS.size()>maxLen){
            ans=newS;
            maxLen=newS.size();
        }

        return ;
    }
    string longestPalindrome(string s) {

        int n=s.size();
        string ans="";
        int maxLen=0;

        for(int i=0;i<n;i++){

            //we are assuming i th is the middle index of pallindrome and expanding 
            //now pallindrome cane be of even size and also odd size so considering the middles as per it 

            string oddPallindrome=returnPallindrome(s,i,i);
            updateAns(oddPallindrome,ans,maxLen);
            string evenPallindrome=returnPallindrome(s,i,i+1);
            updateAns(evenPallindrome,ans,maxLen);
        }

        return ans;

        
    }
};