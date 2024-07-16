class Solution {
public:
    bool isEmpty(int row,int col,vector<vector<char>>& board){
        return(board[row][col]=='.');
    }
    bool isSafe(char num,int row,int col,vector<vector<char>>& board){

        

        for(int i=0;i<9;i++){
            if(board[row][i]==num) return false;
        }

        for(int i=0;i<9;i++){
            if(board[i][col]==num) return false;
        }

        int s=sqrt(9);

        int subGridStartRow=row-row%s;
        int subGridStartCol=col-col%s;


        for(int i=0;i<s;i++){
            for(int j=0;j<s;j++){
                if(board[i+subGridStartRow][j+subGridStartCol]==num) return false;
            }
        }

        return true;


        
    }

    bool fun(vector<vector<char>>& board){


        for(int row=0;row<9;row++){
            for(int col=0;col<9;col++){

                if(isEmpty(row,col,board)){

                    for(char n='1';n<='9';n++){

                        if(isSafe(n,row,col,board)){

                            board[row][col]=n;

                            if(fun(board)) return true;

                            board[row][col]='.';
                        }
                    }

                    return false;
                }
            }
        }

        return true;




        
    }
    void solveSudoku(vector<vector<char>>& board) {

        bool x=fun(board);
    }
};