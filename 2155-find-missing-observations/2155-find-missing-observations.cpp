class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {

        vector<int>ans(n);

        int m=rolls.size();

        //sum of given observatios
        int mSum=accumulate(rolls.begin(),rolls.end(),0);

        //finding sum of missing observations
        int nSum=(mean*(n+m))-mSum;

        //we need to divide the nSum to n slots fully
        int minValue=nSum/n;

        //if we divide and get value for each slot > 6 so not possible as dice and this div value is minimum
        if( (nSum<n)  || (nSum>(6*n)) ) return {};

        //else we proceed to put values
        for(int i=0;i<n;i++){
            ans[i]=minValue;
        }

        if( (nSum%n)==0 ) return ans;

        int remaining=nSum%n;

        for(int i=0;i<n;i++){

            if(ans[i]==6) continue;

            int temp=ans[i]+remaining;

            if(temp <=6 ){
                ans[i]=temp;
                remaining=0;
            }

            else if(temp > 6){

                ans[i]=6;

                remaining=temp-6;

            }

            if(remaining<=0) break;
        }

        return ans;

        









        return ans;

    }
       



        
};