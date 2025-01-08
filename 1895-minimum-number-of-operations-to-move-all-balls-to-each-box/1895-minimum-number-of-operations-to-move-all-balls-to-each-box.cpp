class Solution {
public:
    vector<int> minOperations(string boxes) {

        int n=boxes.size();
        vector<int>ans(n,0);

        int leftBallsToI=0;
        int costTillPrevBox=0;

        for(int i=0;i<n;i++){

            costTillPrevBox=costTillPrevBox+leftBallsToI;
            //imagine as this
            //bring all balls to left adjacent box of i + remove all balls from left adjacent of i to i
            //==leftBallsToI*1 ==leftBallsToI

            ans[i]+=costTillPrevBox;


            if(boxes[i]=='1') leftBallsToI++;
            
        }

        
        int rightBallsToI=0;
        int costTillNextBox=0;

        for(int i=n-1;i>=0;i--){
            costTillNextBox=costTillNextBox+rightBallsToI;
            ans[i]+=costTillNextBox;

            //same observation just from right to left

            if(boxes[i]=='1') rightBallsToI++;

        }



        return ans;
        
    }
};