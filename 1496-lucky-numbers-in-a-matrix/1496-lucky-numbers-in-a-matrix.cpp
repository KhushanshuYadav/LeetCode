class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {

        int m=matrix.size();
        int n=matrix[0].size();

        int rowMinMax=0;
        for(auto& v:matrix){
            int rowMin=1e6;
            for(int& i:v){
                rowMin=min(rowMin,i);
            }
            rowMinMax=max(rowMinMax,rowMin);
        }

        int colMaxMin=1e6;
        for(int col=0;col<n;col++){
            int colMax=0;
            for(int row=0;row<m;row++){
                colMax=max(colMax,matrix[row][col]);
            }
            colMaxMin=min(colMaxMin,colMax);
        }

        if(colMaxMin==rowMinMax) return{colMaxMin};
        return {};
    }
};