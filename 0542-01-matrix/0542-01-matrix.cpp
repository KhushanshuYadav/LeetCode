class Solution {
    int delR[4]={-1,0,+1,0};
    int delC[4]={0,+1,0,-1};

    int isValid(int& i,int& j,int& rows,int& cols){
        return (i<rows && i>=0 && j<cols && j>=0);
    }
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int n=mat.size();
        int m=mat[0].size();

        vector<vector<int>>ans(n,vector<int>(m,-1));

        queue<vector<int>>q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(mat[i][j]==1)  continue;
                
                ans[i][j]=0;
                q.push({i,j});
            }
        }

        while(!q.empty()){

            int i=q.front()[0];
            int j=q.front()[1];
            q.pop();

            for(int k=0;k<4;k++){

                int newI=i+delR[k];
                int newJ=j+delC[k];

                if(isValid(newI,newJ,n,m) && ans[newI][newJ]==-1){
                    ans[newI][newJ]=ans[i][j]+1;
                    q.push({newI,newJ});
                }

            }
        }

        return ans;

       
       
       
        
    }
};