class Solution {
    bool isObs(vector<int>&nextPos,vector<vector<int>>& obstacles){

        if(obstacles.size()==0) return false;

        for(auto& v:obstacles){
            if(nextPos==v) return true;
        }

        return false;
    }
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        
        //map of (move direction,new direction) from current direction

        set< vector<int> >obs(obstacles.begin(),obstacles.end());

        unordered_map<int,string>north;
        north[-2]="west";
        north[-1]="east";

        unordered_map<int,string>south;
        south[-2]="east";
        south[-1]="west";

        unordered_map<int,string>east;
        east[-2]="north";
        east[-1]="south";

        unordered_map<int,string>west;
        west[-2]="south";
        west[-1]="north";

        string dir="north";

        vector<int>currPos(2,0);

        

        int ans=0;
        for(int& move:commands){

            if(move==-1 || move==-2){

                if(dir=="north"){

                    dir=north[move];

                }
                else if(dir=="south"){

                    dir=south[move];
                    
                }
                else if(dir=="east"){

                    dir=east[move];
                    
                }
                else if(dir=="west"){

                    dir=west[move];
                    
                }
            }

            else{

                if(dir=="north"){

                    for(int k=1;k<=move;k++){

                        int currX=currPos[0];
                        int currY=currPos[1];

                        vector<int>nextPos={currX,currY+1};

                        if( obs.count(nextPos) ){
                            break;
                        }
                        else{
                           currPos=nextPos;
                        }

                        currX=currPos[0];
                        currY=currPos[1];

                        ans =max(ans,(currX*currX+currY*currY) );
                    }

                }

                else if(dir=="south"){

                    for(int k=1;k<=move;k++){

                        int currX=currPos[0];
                        int currY=currPos[1];

                        vector<int>nextPos={currX,currY-1};

                        if(obs.count(nextPos)){
                            break;
                        }
                        else{
                            currPos=nextPos;
                        }

                        currX=currPos[0];
                        currY=currPos[1];

                        ans =max(ans,(currX*currX+currY*currY) );
                    }
                    
                }

                else if(dir=="east"){

                    for(int k=1;k<=move;k++){

                        int currX=currPos[0];
                        int currY=currPos[1];

                        vector<int>nextPos={currX+1,currY};

                        if(obs.count(nextPos)){
                            break;
                        }
                        else{
                            currPos=nextPos;
                        }

                        currX=currPos[0];
                        currY=currPos[1];

                        ans =max(ans,(currX*currX+currY*currY) );
                    }

                }

                else if(dir=="west"){

                    for(int k=1;k<=move;k++){

                        int currX=currPos[0];
                        int currY=currPos[1];

                        vector<int>nextPos={currX-1,currY};

                        if(obs.count(nextPos)){
                            break;
                        }
                        else{
                            currPos=nextPos;
                        }

                        currX=currPos[0];
                        currY=currPos[1];

                       ans =max(ans,(currX*currX+currY*currY) );
                    }

                }
            }
        }

      

        

        return ans;
    }
};