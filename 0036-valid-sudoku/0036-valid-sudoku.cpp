class Solution {

    bool check(char& c,int& row,int& col, vector<vector<char>>& board){

        

        for(int i=0;i<9;i++) if(i!=col && board[row][i]==c) return false;
        
        for(int i=0;i<9;i++) if(i!=row && board[i][col]==c) return false;

        int sR=row-row%3;
        int sC=col-col%3;

        for(int i=sR;i<sR+3;i++){
            for(int j=sC;j<sC+3;j++){
                if(i!=row && j!=col && board[i][j]==c) return false;
            }
        }

        return true;

    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){

                if(board[i][j]!='.'){
                    
                    if( !check(board[i][j],i,j,board) ) return false;
                }

            }
        }

        return true;
        
    }
};