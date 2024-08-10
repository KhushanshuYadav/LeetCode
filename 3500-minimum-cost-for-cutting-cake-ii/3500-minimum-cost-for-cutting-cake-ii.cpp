class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {

        sort(horizontalCut.rbegin(),horizontalCut.rend());
        sort(verticalCut.rbegin(),verticalCut.rend());

        int horizontalBCount=1;
        int verticalBcount=1;

        int i=0;
        int j=0;
        long long ans=0;

        while(i<m-1 && j<n-1){

            if(horizontalCut[i]>verticalCut[j]){
                //we made horizontal cuts on all vertcal blocks

                ans+=(horizontalCut[i]*verticalBcount);

                //number of horizontal blocks will inc
                horizontalBCount++;



                i++;
            }
            else{
                //we made vertical cuts on all horizontal blocks

                ans+=(verticalCut[j]*horizontalBCount);

                //number of vertical blocks will inc
                verticalBcount++;



                j++;
            }
        }

        while(i<m-1){

            ans+=(horizontalCut[i]*verticalBcount);
            horizontalBCount++;



            i++;

        }

        while(j<n-1){

            ans+=(verticalCut[j]*horizontalBCount);
            verticalBcount++;



            j++;

        }





        return ans;
        
    }
};