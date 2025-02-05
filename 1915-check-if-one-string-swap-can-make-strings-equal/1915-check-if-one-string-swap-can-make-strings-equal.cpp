class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {

        int count=0;

        int n=s1.size();

        char c1,c2,c3,c4;

        for(int i=0;i<n;i++){

            if(s1[i]!=s2[i]) {
                count++;
                if(count==1){
                    c1=s1[i];
                    c2=s2[i];
                }

                else if(count==2){
                    c3=s1[i];
                    c4=s2[i];
                }
                
            }
        }

        if(count!=2 && count!=0) return false;

        if(count==0) return true;

        return (c1==c4 && c3==c2);



        
    }
};