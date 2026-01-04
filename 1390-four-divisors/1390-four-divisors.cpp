class Solution {
    int solve(int n){

        int ans=0;
        int d=0;

        for(int f=1;f*f<=n;f++){

            if(n%f==0){
                int f2=n/f;

                if(f2==f){
                    d++;
                    ans+=f;
                }

                else{
                    d+=2;
                    ans+=(f+f2);
                }
            } 

            if(d>4) return 0;
        }
        return d==4?ans:0;
    }
public:
    int sumFourDivisors(vector<int>& nums) {

        int ans=0;

        for(int&i:nums) ans+=solve(i);

        return ans;
        
    }
};