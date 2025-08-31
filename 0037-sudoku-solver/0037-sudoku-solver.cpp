class Solution {
public:
    bool isEmpty(int row,int col,vector<vector<char>>& board){
        return(board[row][col]=='.');
    }
    bool isSafe(char num,int row,int col,vector<vector<char>>& board){

        //3=sqrt(9)

        

        for(int i=0;i<9;i++){
            if(board[row][i]==num ||board[i][col]==num ) return false;

            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==num) return false;
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