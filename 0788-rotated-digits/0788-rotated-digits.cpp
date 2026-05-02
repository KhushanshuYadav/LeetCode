class Solution {
public:
    int rotatedDigits(int n) {

        int ans=0;

        for(int j=0;j<=n;j++){
            
            int count=0;
            

            int i=j;
            
            while(i){

                int last=i%10;
                if(last==3 || last==4 || last==7){
                    count=-1;
                    break;
                }
                else if(last !=0 && last !=1 && last !=8) count=1;
                    
                
                i=i/10;

            }

            
            if(count>0) ans++;
        }

        return ans;
        
    }
};