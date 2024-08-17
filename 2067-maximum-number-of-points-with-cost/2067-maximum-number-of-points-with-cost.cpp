class Solution {

public:
    long long maxPoints(vector<vector<int>>& points) {

        int rows=points.size();
        int cols=points[0].size();

        //TABULATION;

        vector<long long >prevRow(cols,0);
        //each cell i,j stores max value till i,j amongs all path from prevRow

        for(int col=0;col<cols;col++){
            prevRow[col]=points[0][col]; //for 0th row no prev row exist
        }
        

        for(int row=1;row<rows;row++){

            vector<long long> currRow(cols,0);
            vector<long long> left(cols,0);
            vector<long long> right(cols,0);

            left[0]=prevRow[0];
            for(int col=1;col<cols;col++){
                left[col]=max(prevRow[col], left[col-1]-1);
            }


            right[cols-1]=prevRow[cols-1];
            for(int col=cols-2;col>=0;col--){
                right[col]=max(prevRow[col], right[col+1]-1);
            }

            for(int col=0;col<cols;col++){

                currRow[col]=points[row][col]+max(left[col],right[col]);


                
            }
            

            


            prevRow=currRow;


        }

        return *max_element(prevRow.begin(),prevRow.end());
    }
};