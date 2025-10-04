class Solution {
     
    int delR[4]={-1,0,+1,0};
    int delC[4]={0,+1,0,-1};

    int isValid(int& i,int& j,int& rows,int& cols){
        return (i>=rows || i<0 || j>=cols || j<0);
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        vector<vector<int>>ans=image;

        int rows=image.size();
        int cols=image[0].size();

        int oC=image[sr][sc];

        queue<vector<int>>q;

        ans[sr][sc]=color;

        q.push({sr,sc});

        while(!q.empty()){

            int i=q.front()[0];
            int j=q.front()[1];

            q.pop();

            for(int k=0;k<4;k++){
                
                int nI=i+delR[k];
                int nJ=j+delC[k];

                if(!isValid(nI,nJ,rows,cols) && ans[nI][nJ]==oC &&  color!=oC){

                    ans[nI][nJ]=color;
                    q.push({nI,nJ});

                }
            }
        }

        return ans;


        
    }
};