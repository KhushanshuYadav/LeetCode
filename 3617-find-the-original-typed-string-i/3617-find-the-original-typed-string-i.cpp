class Solution {
public:
    int possibleStringCount(string word) {

        int n=word.size();

        int l=0;
        int r=0;
        int ans=0;

        while(r<n){

            cout<<l<<" "<<r<<endl;

            if(word[l]!=word[r]){
                ans+=(r-l-1);
                cout<<"ans"<<ans<<endl;
                l=r;
            }

            r++;




        }

        ans+=(r-l);

        return ans;
        
    }
};