class Solution {
private:
    int fun(int ball1, int ball2){
        //ball1 is the one we place first
        int ans=0;
        int level=1;

        while(true){
            if(level%2==1){
                //level with the ball we started
                if(ball1>=level){
                    ball1-=level;
                }
                else break;
            }
            else{
                //we place ball 2
                if(ball2>=level){
                    ball2-=level;
                }
                else break;
            }

            level++;
            ans++;
        }

        return ans;
    }
public:
    int maxHeightOfTriangle(int red, int blue) {
        
        int ans=max(fun(red,blue),fun(blue,red));
        return ans;


    }
};