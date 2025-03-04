class Solution {
public:
    bool checkPowersOfThree(int n) {

        vector<int>v(16,0);
        vector<int>vis(16,0);

        for(int i=0;i<16;i++){
            v[i]=pow(3,i);
        }


        while(n){

            int x=-1;
            for(int i=0;i<16-1;i++){

                if(v[i]==n && !vis[i]){
                    x=v[i];
                    vis[i]=1;

                    return true;
                }
                else if(v[i+1]>n && !vis[i]){
                    x=v[i];
                    vis[i]=1;
                    break;
                }
            }

            if(x==-1) return false;


            n=n-x;


        }

        return true;
        
    }
};