    class Solution {
        int delR[4]={-1,0,+1,0};
        int delC[4]={0,+1,0,-1};

        int isValid(int& i,int& j,int& rows,int& cols){
            return (i<rows && i>=0 && j<cols && j>=0);
        }
    public:
        vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

            int rows=mat.size();
            int cols=mat[0].size();

            for(int i=0;i<rows;i++){
                for(int j=0;j<cols;j++){

                    if(mat[i][j]==0) continue;


                    int mn=INT_MAX;
                    for(int k=0;k<4;k+=3){

                        int newI=i+delR[k];
                        int newJ=j+delC[k];

                        if(isValid(newI,newJ,rows,cols)){
                            mn=min(mn,mat[newI][newJ]);
                        }
                    
                    }

                    if(mn!=INT_MAX) mn+=1;

                    mat[i][j]=mn;

                        
                    
                }
            }

            for(int i=rows-1;i>=0;i--){
                for(int j=cols-1;j>=0;j--){

                    if(mat[i][j]==0) continue;


                    int mn=INT_MAX;
                    for(int k=1;k<3;k+=1){

                        int newI=i+delR[k];
                        int newJ=j+delC[k];

                        if(isValid(newI,newJ,rows,cols)){
                            mn=min(mn,mat[newI][newJ]);
                        }
                    
                    }
                    if(mn!=INT_MAX) mn+=1;

                    mat[i][j]=min(mat[i][j],mn);

                        
                    
                }
            }
            return mat;
            
        }
    };