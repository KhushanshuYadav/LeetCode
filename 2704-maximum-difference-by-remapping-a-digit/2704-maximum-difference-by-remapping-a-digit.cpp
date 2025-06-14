class Solution {
public:
    int minMaxDifference(int num) {

        string sMax=to_string(num);
        string sMin=to_string(num);

        char maxReplace,minReplace;

        int n=sMax.size();

        bool f1=1;
        bool f2=1;
        

        for(int i=0;i<n;i++){

            if(sMax[i]!='9' && f1) {maxReplace=sMax[i];f1=false;}
            cout<<maxReplace<<endl;

            if(sMax[i]!='0' && f2) {minReplace=sMax[i];f2=false;}
            cout<<minReplace<<endl;
        }


        for(int i=0;i<n;i++){
            if(sMax[i]==maxReplace){
                sMax[i]='9';
               
            }

            if(sMin[i]==minReplace){
                sMin[i]='0';

            }
        }

        int ans=stoi(sMax)-stoi(sMin);

        return ans;

        
    }
};