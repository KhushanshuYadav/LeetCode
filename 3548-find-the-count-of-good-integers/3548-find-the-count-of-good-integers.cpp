class Solution {
   
public:
    long long countGoodIntegers(int n, int k) {

        vector<long long>fact(11,1);

        for(int i=1;i<11;i++){
            fact[i]=i*fact[i-1];
        }

        unordered_set<string>s;
        long long ans=0;

        //we will make n digit pallidrome by mirroring its half digits =d

        int d=(n+1)/2;

        int low=pow(10,d-1); //samllest number with digit count=d;
        int high=pow(10,d)-1; //largest number with digit count=d;

        //generating pallindrom
        for(int i=low;i<=high;i++){

            string leftHalf=to_string(i);

            string fullNum="";

            if(n%2==0){
                string rightHalf=leftHalf;
                reverse(rightHalf.begin(),rightHalf.end());
                fullNum=leftHalf+rightHalf;
            }
            else{
                string rightHalf=leftHalf.substr(0,d-1);
                reverse(rightHalf.begin(),rightHalf.end());
                fullNum=leftHalf+rightHalf;
            }

            //checking divisibility by k
            long long num=stoll(fullNum);

            if(num%k!=0) continue;

            sort(fullNum.begin(),fullNum.end());

            s.insert(fullNum);
        }

        
        for(const string& str:s){

            //storing freq of digits
            vector<int>v(10,0);


            for(const char&c:str) v[c-'0']++;

            int totalDigits=str.size();
            int zeros=v[0];
            int nonZeros=totalDigits-v[0];

            long long perm=(nonZeros*fact[totalDigits-1]);

            for(int i=0;i<10;i++){
                perm/=fact[v[i]];
                //dividing to avoid duuplicates permuations
            }

            ans+=perm;

        }

        return ans;

        
        
    }
};