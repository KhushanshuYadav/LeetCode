class Solution {

    int delR[4]={-1,0,+1,0};
    int delC[4]={0,+1,0,-1};

    int isValid(int& i,int& j,int& rows,int& cols){
        return (i<rows && i>=0 && j<cols && j>=0);
    }

    int isValid1(int& i,int& j,int& rows,int& cols){
        return (i==rows-1 ||i==0 || j==cols-1 || j==0);
    }

    void dfs(int i,int j,vector<vector<char>>& board,int& n,int& m){
        board[i][j]='1';

        for(int k=0;k<4;k++){
            int newI=i+delR[k];
            int newJ=j+delC[k];

            if(isValid(newI,newJ,n,m) && board[newI][newJ]=='O') dfs(newI,newJ,board,n,m);
        }
    }

public:
    void solve(vector<vector<char>>& board) {

        int n=board.size();
        int m=board[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(board[i][j]=='O' && isValid1(i,j,n,m)) dfs(i,j,board,n,m);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(board[i][j]=='O') board[i][j]='X';

                else if(board[i][j]=='1') board[i][j]='O';

                
            }
        }



        
    }
};