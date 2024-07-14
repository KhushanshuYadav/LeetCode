class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        //int n = edges.size();
        vector<vector<int>> matrix(n, vector<int>(n, -1));

        for (auto& v : edges) {
            matrix[v[0]][v[1]] = v[2];
            matrix[v[1]][v[0]] = v[2];
        }

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < n; j++) {

                if (i == j)
                    matrix[i][j] = 0;

                else if (matrix[i][j] == -1)
                    matrix[i][j] = 1e9;
            }
        }

        for (int k = 0; k < n; k++) {

            for (int i = 0; i < n; i++) {

                for (int j = 0; j < n; j++) {
                    matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]);
                }
            }
        }

        int ans=-1;
        int count=INT_MAX;

        for(int i=0;i<n;i++){

            int tempCount=0;

            for(int j=0;j<n;j++){

                //if(i==j) continue;

                if(matrix[i][j]<=distanceThreshold) tempCount++;

            }

            if(tempCount<=count) {ans=i;count=tempCount;}
        }

        return ans;
    }
};