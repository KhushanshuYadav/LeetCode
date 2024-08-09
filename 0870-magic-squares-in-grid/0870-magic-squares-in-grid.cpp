class Solution {
private:
    bool isAns(int row, int col, vector<vector<int>>& grid) {

        unordered_set<int> s;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {

                int num = grid[row + i][col + j];

                if (num < 1 || num >9) return false;

                if (s.count(num))
                    return false;

                s.insert(num);
            }
        }

        int firstDSum = 0;
        for (int i = 0; i < 3; i++) {

            firstDSum += (grid[row + i][col + i]);
        }

        int secondDSum = 0;
        for (int i = 0; i < 3; i++) {

            secondDSum += (grid[row + i][col+2 - i]);
        }

        if (firstDSum != secondDSum) return false;

       int row1 = grid[row][col] + grid[row][col + 1] + grid[row][col + 2];
        int row2 = grid[row + 1][col] + grid[row + 1][col + 1] +
                   grid[row + 1][col + 2];
        int row3 = grid[row + 2][col] + grid[row + 2][col + 1] +
                   grid[row + 2][col + 2];

        if (!(row1 == firstDSum && row2 == firstDSum && row3 == firstDSum)) {
            return false;
        }

        // Check if all column sums are the same as the diagonal sums
        int col1 = grid[row][col] + grid[row + 1][col] + grid[row + 2][col];
        int col2 = grid[row][col + 1] + grid[row + 1][col + 1] +
                   grid[row + 2][col + 1];
        int col3 = grid[row][col + 2] + grid[row + 1][col + 2] +
                   grid[row + 2][col + 2];

        if (!(col1 == firstDSum && col2 == firstDSum && col3 == firstDSum)) {
            return false;
        }

        return true;

    }

public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        if (rows < 3 || cols < 3)
            return 0;

        int ans = 0;

        for (int row = 0; row + 2 < rows; row++) {
            for (int col = 0; col + 2 < cols; col++) {

                if (isAns(row, col, grid))
                    ans++;
            }
        }

        return ans;
    }
};