class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n=bills.size();
        int f=0,t=0,tw=0;

        for(int i=0;i<n;i++){
            if(bills[i]==5) f++;
            else if(bills[i]==10 && f>=1){
                t++;
                
                f--;
            }

            else if(bills[i]==10 && f==0){return false;}

            else{
               
                if(f==0){
                    return false;
                }
                else if(t==0  && f>=3){
                    f-=3;
                    tw++;
                }

                else if(t>=1 && f>=1){
                    t--;
                    f--;
                    tw++;
                }

                else{
                    return false;
                }
            }
        }

        return true;
        
    }

};