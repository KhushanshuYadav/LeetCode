class Solution {


public:
    bool isValidSudoku(vector<vector<char>>& board) {

        vector<bitset<9>>rows(9);
        vector<bitset<9>>cols(9);
        vector<bitset<9>>box(9);


        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){

                if(board[i][j]!='.'){
                    
                    int x=(board[i][j]-'0');

                    int b=(i/3)*3+(j/3);

                    if(rows[i][x] || cols[j][x] || box[b][x]) return false;

                    rows[i][x]=1;
                    cols[j][x]=1;
                    box[b][x]=1;

                   
                }

            }
        }

      

        return true;
        
    }
};