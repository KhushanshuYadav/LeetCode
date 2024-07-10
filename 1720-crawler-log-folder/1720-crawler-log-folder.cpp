class Solution {
public:
    int minOperations(vector<string>& logs) {
        int count=0;  //in main count==0
        //inc count on x/
        //dec count in ../
        //nothing in ./

        for(string &s:logs){
            if(s=="../" && count!=0) count--;
            else if(s=="../" && count==0) continue;
            else if(s=="./") continue;
            else count++;
        }



        if(count<0) return 0; //already in main 
        return count;

        
    }
};