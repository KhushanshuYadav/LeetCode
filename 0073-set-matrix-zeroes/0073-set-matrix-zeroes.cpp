class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int firstOfFirstRow=1;
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>rowWithZero;
	vector<int>coloumnWithZero;

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(matrix[i][j]==0){
				rowWithZero.push_back(i);
				coloumnWithZero.push_back(j);

			}
		}
	}

	for(auto i:rowWithZero){
		for(int j=0;j<m;j++){
			matrix[i][j]=0;
		}
	}

	for(auto i:coloumnWithZero){
		for(int j=0;j<n;j++){
			matrix[j][i]=0;
		}
	}

	//return matrix;

	

    }
};