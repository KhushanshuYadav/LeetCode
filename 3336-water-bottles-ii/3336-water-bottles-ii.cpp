class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {

        int eB=numBottles;

        int ans=numBottles;

        int fB=0;

        while(eB>=numExchange){

            cout<<"eb1 "<<eB<<endl;

            fB=0;

            while(eB>=numExchange){
                cout<<"eb2 "<<eB<<endl;
                eB-=numExchange;
                cout<<"eb3 "<<eB<<endl;
                fB++;
                cout<<"fb1 "<<fB<<endl;
                numExchange++;
                cout<<"numExchange "<<numExchange<<endl;
            }

            ans+=fB;
            cout<<"ans "<<ans<<endl;
            eB+=fB;
            cout<<"eb4 "<<eB<<endl;
        }

        return ans;
        
    }
};