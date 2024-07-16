class Solution {
public:
    string buildString(vector<char>&path){
        string ans="";

        for(char i:path){
            ans.push_back(i);
        }

        return ans;
    }

    bool isSafe(int row,int col,vector<string>&config,int n){

        if(row>=n) return false;

        for(int i=0;i<n;i++){
            if(config[i][col]=='Q') return false;
        }

        //upper left diagonal
        int i=row,j=col;
        while(i>=0 && j>=0){
            if(config[i][j]=='Q') return false;

            i--;
            j--;
        }

        //upper right diagonal
        i=row,j=col;
        while(i>=0 && j<n){

            if(config[i][j]=='Q') return false;
            
            i--;
            j++;
        }

        //lower left diagonal
        i=row,j=col;
        while(i<n && j>=0){

            if(config[i][j]=='Q') return false;
            
            i++;
            j--;
        }

        //lower right diagonal
        i=row,j=col;
        while(i<n && j<n){

            if(config[i][j]=='Q') return false;
            
            i++;
            j++;
        }


        return true;


    }

    void fun(int row, vector<vector<string>>&ans,vector<string>&config,int& n){
        if(row==n){
            ans.push_back(config);
           // count=0;
            //config.clear();
            return;
        
        }

        else{

            for(int col=0;col<n;col++){

                //vector<char>path(n,'.');

                if(isSafe(row,col,config,n)){

                    //count++;


                    config[row][col]='Q';
                    //path[col]='Q';
                    
                    //string s=buildString(path);
                    //config.push_back(s);


                    fun(row+1,ans,config,n);

                    //path[col]='.';


                    config[row][col]='.';
                    //config.pop_back();



                    



                }
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {

        //vector<vector<char>>grid(n,vector<char>(n,'.'));
        vector<vector<string>>ans;
        vector<string>config(n,string(n,'.'));
        //string pos;

        int row=0;
        int count=0;
        
        fun(row,ans,config,n);

        return ans;
        
    }
};