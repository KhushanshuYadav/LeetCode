class Solution {

    int fun(int n){
        int sum=0;
        while(n){
            int lastDigit=n%10;
            sum+=lastDigit;
            n=n/10;
        }

        return sum;
    }
public:
    int countLargestGroup(int n) {

        vector<int>v(37,0);

        int ans=0;
        int count=1;

        for(int i=1;i<=n;i++){

            int freq=++v[fun(i)];

            if(freq>ans) {
                count=1;
                ans=freq;
            }

            else if(freq==ans)count++;
        }
        return count;

        
        
    }
};