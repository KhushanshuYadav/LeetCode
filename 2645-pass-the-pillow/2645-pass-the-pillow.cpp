class Solution {
public:
    int passThePillow(int n, int time) {

        int i=1;
        bool isF=true;


        while(time--){

            if(isF) i++;
            else i--;

            if(i==n) isF=false;
            else if(i==1) isF=true;

        }

        return i;
    }
};