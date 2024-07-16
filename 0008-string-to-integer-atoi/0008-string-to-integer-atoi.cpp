class Solution {
public:
    int myAtoi(string s) {

        int n=s.size();

        long ans=0;

        int sign=1;

        int i=0;

        while(i<n && s[i]==' ') i++;

        if(s[i]=='-') {sign=(-1*sign);i++;}

        else if(s[i]=='+'){i++;}

        //if(s[i]>='0' && s[i]<='9') return ans;

        //while (i < n && s[i] == '0') i++;
        

        while(i<n && s[i]>='0' && s[i]<='9' ){

            ans=(ans*10)+(s[i]-'0');

           


            if((sign*ans)>INT_MAX) return INT_MAX;
            if((sign*ans)<=INT_MIN) return INT_MIN;
            
            i++;
        }

        ans=(sign*ans);

        return (int)ans;


        
    }
};