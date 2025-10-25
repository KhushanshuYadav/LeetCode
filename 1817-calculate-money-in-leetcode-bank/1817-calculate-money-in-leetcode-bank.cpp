class Solution {
public:
    int totalMoney(int n) {

        int ans=0;

        int n1=n/7;

        int start=1;

        for(int i=1;i<=n1;i++){
            start++;
            ans+=(28+(7*(i-1)));
        }
        cout<<start<<endl;

        int temp=n%7;

        while(temp--){
            ans+=start;

            start++;
        }
        
       

        return  ans;
    }
};