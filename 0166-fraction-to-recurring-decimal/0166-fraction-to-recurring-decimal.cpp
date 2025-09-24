    class Solution {
    public:
        string fractionToDecimal(int numerator, int denominator) {

            string ans="";

            if(numerator==0) return "0";

            if ((numerator < 0) ^ (denominator < 0)) {ans += "-";}

            long long n = numerator;
            long long d = denominator;

            n=abs(n);
            d=abs(d);


            unordered_map<int,int>m;//rem,pos

            long long num=n;

            ans+=format("{}",num/d);

            if(num%d!=0) ans.push_back('.');

            int i=ans.size();

            while(num%d!=0){

                int rem=num%d;
                num=(long long)rem*10;

                if(m.count(rem)){
                    int pos=m[rem];
                    ans.insert(pos,1,'(');
                    ans.push_back(')');

                    return ans;
                }


                ans+=format("{}",num/d);
            

            
                
                m[rem]=i;
                i++;

                

            }

            return ans;
        }
    };