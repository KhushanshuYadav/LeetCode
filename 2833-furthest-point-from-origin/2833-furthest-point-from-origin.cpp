class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {

        int ans1=0;
        int ans2=0;

        for(char&c:moves) {

            if(c=='L') {
                ans1--;
                ans2--;
            }

            else if(c=='R') {
                ans1++;
                ans2++;
            }

            else{
                ans1--;
                ans2++;
            }
        }

        // int ans=0;
        // for(char&c:moves){

        //     if(c=='L') ans--;
        //     else if(c=='R') ans++;
        //     else ans+=(l>=r?-1:+1);

        // }

        return max(abs(ans1),abs(ans2));


        
    }
};