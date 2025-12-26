class Solution {
public:
    int bestClosingTime(string customers) {

        int n=customers.size();

        int totalY=0;
        int totalN=0;

        for(char&c:customers){
            if(c=='Y') totalY++;
            else totalN++;
        }

       // cout<<"A "<<totalY<<" "<<totalN<<endl;

        int ans=0;

        int currY=0;
        int currN=0;

        int minP=INT_MAX;

        for(int i=0;i<n;i++){

            char c=customers[i];

            int p=0;

            if(c=='Y'){ 
                currY++;
                p=currN+(totalY-currY+1);
            }

            else {
                currN++;
                p=(currN-1)+(totalY-currY);
            }

             

           // cout<<i<<" "<<c<<" "<<currY<<" "<<currN<<" "<<p<<" "<<minP<<endl;

            if(p<minP){
               
                
                minP=p;
                ans=i;

                //cout<<"in "<<minP<<" "<<ans<<endl;

            }


        }

        int p=totalN;

        if(p<minP){
            ans=n;
        }

        

        return currY==n?n:ans;
        
    }
};