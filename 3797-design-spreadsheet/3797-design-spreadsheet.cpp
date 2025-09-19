class Spreadsheet {
    //vector<vector<int>>val;

    unordered_map<string,int>val;
public:
    Spreadsheet(int rows) {
       // val.resize(rows,vector<int>(26,0));
    }
    
    void setCell(string cell, int value) {
        val[cell]=value;

    }
    
    void resetCell(string cell) {
        val[cell]=0;
        
    }
    
    int getValue(string formula) {

        int i=1;

        string cell1="";

        string cell2="";
        
        while(formula[i]!='+'){
            cell1.push_back(formula[i]);
            i++;
        }

        int val1=0;

        if(isupper(cell1[0])) val1=val[cell1];
        else val1=stoi(cell1);

        i++;

        while(i<formula.size()){
            cell2.push_back(formula[i]);
            i++;
        }

        int val2=0;

        if(isupper(cell2[0])) val2=val[cell2];
        else val2=stoi(cell2);

        return val1+val2;



        
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */