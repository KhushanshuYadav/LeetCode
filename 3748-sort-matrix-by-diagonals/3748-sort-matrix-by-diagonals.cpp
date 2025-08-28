class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {

        int n=grid.size();

        unordered_map<int,priority_queue<int,vector<int>,greater<int>>>above;
        unordered_map<int,priority_queue<int>>below;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){

                if(i<j){
                    //upper dia

                    above[j-i].push(grid[i][j]);
                }

                else if(i>=j){
                    //lower dia
                    below[i-j].push(grid[i][j]);

                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){

                if(i<j){
                    //upper dia

                    grid[i][j]=above[j-i].top();
                    above[j-i].pop();

                }

                else if(i>=j){
                    //lower dia
                    grid[i][j]=below[i-j].top();
                    below[i-j].pop();

                }

            }

            
        }
        return grid;



        
    }
};
