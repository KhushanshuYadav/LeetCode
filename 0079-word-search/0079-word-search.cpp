class Solution {

    int delR[4]={-1,0,+1,0};
    int delC[4]={0,+1,0,-1};

    bool solve(int i, int j, int k, vector<vector<char>>& board, string& word) {
        
        // Base Case: If k equals word length, we found the whole word!
        // Note: Check this usually implies we matched the last char successfully in previous step
        if (k == word.size()) return true;

        // Boundary & Validity Check
        // 1. Out of bounds?
        // 2. Current cell != word[k]?
        // 3. Cell is visited ('#')?
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[k]) {
            return false;
        }

        // --- Valid Character Found ---

        // 1. Mark as Visited (Mutate)
        char originalChar = board[i][j];
        board[i][j] = '#'; 

        // 2. Recurse in 4 directions
        // Look for the NEXT character (k + 1)
        bool found = solve(i + 1, j, k + 1, board, word) ||
                     solve(i - 1, j, k + 1, board, word) ||
                     solve(i, j + 1, k + 1, board, word) ||
                     solve(i, j - 1, k + 1, board, word);

        // 3. Backtrack (Undo Mutation)
        board[i][j] = originalChar;

        return found;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {


        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                string temp="";
                if(solve(i,j,0,board,word)) return true;
            }
        }

        return false;

        
    }
};