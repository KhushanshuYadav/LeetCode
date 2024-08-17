class Solution {
public:

    int countPrimes(int n) {

        vector<long long int>isPrime(n,1);
        int count=0;

        for(long long int i=2;i<n;i++){

            if(isPrime[i]){

               

                for(long long int j=i*i;j<n;j=j+i){
                    isPrime[j]=0;
                   
                }

                count++;
            }
        }

        return count;



        
    }
};