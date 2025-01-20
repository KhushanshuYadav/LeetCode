class Solution {

    bool fullyPainted(int& row,int& col,vector<vector<int>>& mat,vector<int>isPainted){

        int rows=mat.size();
        int cols=mat[0].size();

        bool isCol=true;
        bool isRow=true;

        for(int i=0;i<rows;i++){

            if(!isPainted[mat[i][col]]){ isCol= false;break;}
            
        }

        
        for(int i=0;i<cols;i++){

            if(!isPainted[mat[row][i]]) {isRow= false;break;}
            
        }

        return (isRow||isCol);
    }
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {

        unordered_map<int,pair<int,int>>m;

        int n=arr.size();
        int rows=mat.size();
        int cols=mat[0].size();

        vector<int>rowCount(rows,0);
        vector<int>colCount(cols,0);

        


        //vector<int>isPainted((rows*cols+1),0);


        for(int i=0;i<rows;i++){

            for(int j=0;j<cols;j++){

                m[mat[i][j]].first=i;
                m[mat[i][j]].second=j;
            }

        }

        for(int i=0;i<n;i++){

            int row=m[arr[i]].first;
            int col=m[arr[i]].second;

            rowCount[row]++;
            colCount[col]++;

            if(rowCount[row]==cols ||colCount[col]==rows ) return i;

            

            

        }

        return -1;
        
    }
};