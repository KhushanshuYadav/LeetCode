class Solution {
public:
    double myPow(double x, int n) {

       
        long long int absN=abs((long long int)n);
        double ans=1.0;

        while(absN){
            if(absN%2){
                ans*=x;
                absN--;
            }
            else{
                x*=x;
                absN/=2;
            }
        }   

        if(n<0) ans= 1.0/(double)ans;

        return ans; 
        
    }
};