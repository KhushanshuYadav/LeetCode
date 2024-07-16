class Solution {
public:
    int largestAreaInHistogram(vector<int>&h){
        stack<int>s;

        int maxA=-1;

        for(int i=0;i<=h.size();i++){
            
            while(!s.empty() && (i==h.size() || h[i]<h[s.top()])){
                int height=h[s.top()];

                s.pop();

                int width=(s.empty())?i:i-s.top()-1;

                int currA=height*width;

                maxA=max(maxA,currA);
            }

            

            s.push(i);
        }

        return maxA;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {

        vector<int> heights(matrix[0].size(), 0);

        for (int j = 0; j < matrix[0].size(); j++) {
            heights[j] = matrix[0][j] - '0';
        }

        int maxA=largestAreaInHistogram(heights);

        for(int i=1;i<matrix.size();i++){

            for(int j=0;j<matrix[0].size();j++){

                if (matrix[i][j] == '1') {
                    heights[j] ++;
                } else {
                    heights[j] = 0;
                }
            }

            maxA=max(maxA,largestAreaInHistogram(heights));
        }

        return maxA;
        
    }
};