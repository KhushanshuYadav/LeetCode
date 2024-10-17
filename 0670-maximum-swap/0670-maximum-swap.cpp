class Solution {
public:
    int maximumSwap(int num) {

        string s=to_string(num);
        int n=s.size();

        
        bool flag=false;

        for(int i=0;i<n;i++){

            char mx=s[i];
            int mxInd=i;

            for(int j=n-1;j>=i+1;j--){

                if(s[j]>s[mxInd]){
                    mxInd=j;
                    mx=s[j];
                }
            }

            if(mxInd!=i) {
                swap(s[i],s[mxInd]);
                break;
            }



        }

       

        

        int ans=stoi(s);

        return ans;
        
    }
};