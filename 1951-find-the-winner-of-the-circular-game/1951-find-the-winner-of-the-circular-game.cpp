class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int>q;

        for(int i=1;i<=n;i++){
            q.push(i);
        }

        while(q.size()!=1){
            int count=0;
            int j=k;
            while(j--){
                int x=q.front();
                q.pop();
                count++;
                if(count!=k){

                    q.push(x);

                }

            }
        }

        return q.front();
    }
};