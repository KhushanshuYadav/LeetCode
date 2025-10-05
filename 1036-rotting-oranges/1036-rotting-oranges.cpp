class Solution {

    int delR[4]={-1,0,+1,0};
    int delC[4]={0,+1,0,-1};

    int valid(int& i,int& j,int& rows,int& cols){
        return (i<rows && i>=0 && j<cols && j>=0);
    }

   
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int rows=grid.size();
        int cols=grid[0].size();

        queue<vector<int>>q;

        int ans=0;

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){

                if(grid[i][j]==2) q.push({i,j});

                

            }
        }

        
        while(!q.empty()){

            bool f=false;

            int s=q.size();

            for(int i=0;i<s;i++){

               

                int r=q.front()[0];
                int c=q.front()[1];
                q.pop();

                for(int i=0;i<4;i++){

                    int newR=r+delR[i];
                    int newC=c+delC[i];

                    if(valid(newR,newC,rows,cols) && grid[newR][newC]==1){
                        grid[newR][newC]=2;
                        f=true;
                        q.push({newR,newC});
                    
                    }
                }

            }

            if(f) ans++;



            

          
        }



        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==1) return -1;
            }
        }

        return ans;
        
    }
};