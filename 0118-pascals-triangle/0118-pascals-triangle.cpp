class Solution {
public:
    vector<vector<int>> generate(int numRows) {

        vector<vector<int>>v;

        if(numRows==1){
            v.push_back({1});
            return v;
        }
        else if(numRows==2){
            v.push_back({1});
            v.push_back({1,1});
            return v;
        }

        v.push_back({1});
        v.push_back({1,1});

        for(int i=2;i<numRows;i++){
            vector<int>temp;
            temp.push_back(1);
            for(int j=0;j<v[i-1].size()-1;j++){
                temp.push_back(v[i-1][j]+v[i-1][j+1]);

            }
            
            temp.push_back(1);
            v.push_back(temp);
        }

        return v;
    }
};