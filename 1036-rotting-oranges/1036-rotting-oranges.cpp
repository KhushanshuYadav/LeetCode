class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int deltaR[] = {-1, 0, 1, 0};
        int deltaC[] = {0, 1, 0, -1};

        int ans = -1;
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;

        int count = 0;
        for (int i = 0; i < n; i++) {

            for (int j = 0; j < m; j++) {

                if (grid[i][j] == 1)
                    count++;
                else if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }

        int c1 = 0;

        while (!q.empty()) {

            int s = q.size();
            while (s--) {

                auto p = q.front();
                int r = p.first;
                int c = p.second;
                //int t = p.second;

                q.pop();

                for (int i = 0; i < 4; i++) {
                    int nR = r + deltaR[i];
                    int nC = c + deltaC[i];
                    if (nR >= 0 && nR < n && nC >= 0 && nC < m &&
                        grid[nR][nC] == 1) {
                        grid[nR][nC] = 2;
                        q.push({nR, nC});
                        c1++;
                    }
                }
            }

            ans++;
        }

        if (count != c1 )
            return -1;
        if(ans==-1) return 0;
        return ans;
    }
};