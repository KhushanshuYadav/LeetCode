class Solution {

    int delR[4]={-1,0,+1,0};
    int delC[4]={0,+1,0,-1};

    int r;
    int c;

    
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        int rows=heights.size();
        int cols=heights[0].size();

        

        vector<vector<int>>dis(rows,vector<int>(cols,INT_MAX));//store min across all paths

        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;

        pq.push({0,0,0});
        dis[0][0]=0;

        while(!pq.empty()){

            int C=pq.top()[0]; //cost till r,c from 0,0
            int r=pq.top()[1];
            int c=pq.top()[2];

            pq.pop();

            if(r==rows-1 && c==cols-1) return C;

            if(C>dis[r][c]) continue;      //C can be == or > not < to avoid stale entry

            for(int k=0;k<4;k++){

                int newR=r+delR[k];
                int newC=c+delC[k];

                if(newR>=0 && newR<rows && newC>=0 && newC<cols){

                    int cost =abs(heights[newR][newC]-heights[r][c]); //cost from r,c to newR,newC

                    int maxPathCost=max(cost,C);  //the max cost of curr path either of r,c or newR,newC as both in same path

                    if(dis[newR][newC]>maxPathCost){
                        dis[newR][newC]=maxPathCost;
                        pq.push({dis[newR][newC],newR,newC});
                    }


                }

            }
        }


        return 0;
        


        
    }
};