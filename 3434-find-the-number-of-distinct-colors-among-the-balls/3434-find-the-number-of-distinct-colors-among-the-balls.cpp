class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {

        unordered_map<int,int>bToC; //ball,color
        unordered_map<int,int>cToB;//color,ball count

        vector<int>ans;


        for(auto& q:queries){

            int ball=q[0];
            int color=q[1];

            if( bToC.count(ball) ){

                int ballColor=bToC[ball];
                cToB[ballColor]--;
                if(cToB[ballColor]==0) cToB.erase(ballColor);
            }

            bToC[ball]=color;
            cToB[color]++;

            ans.push_back(cToB.size());



        }

        return ans;
        
    }
};