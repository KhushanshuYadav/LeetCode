class Solution {
public:
    int findComplement(int num) {\

        int power=0;
        int ans=0;

        while(num>0){
              

            if((num&1)==0){


                ans+=(pow(2,power)*1);
                

               

                

            }

            
            num=num>>1;
            power++;
        }

        return ans;
       
    }
};