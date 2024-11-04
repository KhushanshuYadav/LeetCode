class Solution {
public:
    string compressedString(string s) {

        int n=s.size();
        string c="";
        int cnt=0;
        int l=0,r=0;

        while(r<n){
            cnt=0;
            while(r<n && s[r]==s[l] && cnt<9 ){


                cnt++;
                r++;


            }

            c.push_back(cnt+'0');
            c.push_back(s[l]);
            l=r;

           
        }

        return c;

        
        
    }
};