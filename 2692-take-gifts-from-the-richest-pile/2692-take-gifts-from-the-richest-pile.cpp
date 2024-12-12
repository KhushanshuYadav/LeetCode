class Solution {

    int fun1(vector<int>& gifts){

        int ans=-1;
        int mx=INT_MIN;

        for(int i=0;i<gifts.size();i++){

            if(gifts[i]>=mx){
                ans=i;
                mx=gifts[i];
            }


        }

        return ans;
    }

public:
    long long pickGifts(vector<int>& gifts, int k) {

        while(k--){

            int idx=fun1(gifts);

            gifts[idx]=floor(sqrt(gifts[idx]));
        
        }

        long long  ans=0;
        for(int i=0;i<gifts.size();i++){

            ans+=gifts[i];

        }

        return ans;
        
    }
};