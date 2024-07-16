class Solution {
public:
    int candy(vector<int>& ratings) {

        int n=ratings.size();

         //the candy that should be ath peak if we go down to up in decreasing slope depth
        int ans=1;

        int i=1;

        while(i<n){

            if(ratings[i]==ratings[i-1]){
                ans++;
                i++;
                continue;

            }


            int peak=1;

            while(i<n && ratings[i]>ratings[i-1]){

                peak++;
                ans+=peak;
                i++;



            }

            int bottom=1;

            while(i<n && ratings[i]<ratings[i-1]){
               
                ans+=bottom;
                bottom++;


                i++;
            }

            if(bottom>peak){
                ans+=(bottom-peak);
            }
           
        }

        return ans;
    }
};