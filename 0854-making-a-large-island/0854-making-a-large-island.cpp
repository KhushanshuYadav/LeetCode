class Solution {

    vector<int>delRow={-1,0,+1,0};
    vector<int>delCol={0,+1,0,-1};

    bool isValid(int& i,int& j,int& n){

        return (i>=0 && i<n && j>=0 && j<n);

    }

    int dfs(int i,int j,vector<vector<int>>& vis,vector<vector<int>>& grid,int& n,int& idN,vector<vector<int>>& id){
        
        vis[i][j]=1;

        id[i][j]=idN;

        int area=1;

        for(int k=0;k<4;k++){

            int newI=i+delRow[k];
            int newJ=j+delCol[k];

            if( isValid(newI,newJ,n) && grid[newI][newJ]==1 && !vis[newI][newJ]  ){
                area+=dfs(newI,newJ,vis,grid,n,idN,id);
            }
        }

        return area;
    }

    void dfsMark(int i,int j,vector<vector<int>>& vis,vector<vector<int>>& grid,vector<vector<int>>& area,int& n,int& a){
        
        vis[i][j]=1;

        area[i][j]=a;

        for(int k=0;k<4;k++){

            int newI=i+delRow[k];
            int newJ=j+delCol[k];

            if( isValid(newI,newJ,n) && grid[newI][newJ]==1 && !vis[newI][newJ]  ){
                dfsMark(newI,newJ,vis,grid,area,n,a);
            }
        }

        return ;
    }



public:
    int largestIsland(vector<vector<int>>& grid) {

        int n=grid.size();

        vector<vector<int>>id(n,vector<int>(n,0));

        vector<vector<int>>vis(n,vector<int>(n,0));

        unordered_map<int,int>m;//id to area

        bool allOne=true;

        int maxA=INT_MIN;

        int idN=2;

        for(int i=0;i<n;i++){

            for(int j=0;j<n;j++){

                if(  grid[i][j] && !vis[i][j] ) {

                    int a=dfs(i,j,vis,grid,n,idN,id);
                    
                   

                    maxA=max(maxA,a);

                    m[idN]=a;

                    idN++;
                }

                
            }
        }

        //fill(vis.begin(), vis.end(), vector<int>(n, 0));
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){

        //         cout<<id[i][j]<<" ";

        //         //if( area[i][j] && !vis[i][j] ) dfsMark(i,j,vis,grid,area,n,area[i][j]);

        //     }
        //     cout<<endl;
        // }

        int ans=maxA+1;
        
        

        for(int i=0;i<n;i++){

            for(int j=0;j<n;j++){

                if(grid[i][j]==0){

                    int temp=1;

                    allOne=false;

                    unordered_set<int>s;

                    for(int k=0;k<4;k++){

                        int newI=i+delRow[k];
                        int newJ=j+delCol[k];



                        if( isValid(newI,newJ,n) && grid[newI][newJ]==1 ){

                            s.insert(id[newI][newJ]);

                        }

                    }

                    for(auto& x:s){

                        temp+=m[x];

                    }

                    ans=max(ans,temp);
                }
            }
       
           
        }

        if(allOne) return n*n;

        return ans;


        
        
    }
};