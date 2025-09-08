class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {

        int place=1;

        int a=n;
        int b=0;

        while(n>1){

            int d=n%10;

            int take=1;

            if(d==1) take=2;

            a=a-(take*place);
            b=b+(take*place);

            n=(n-take)/10;

            place=place*10;

        }

        return {a,b};
        
    }
};