class Solution {

    bool allOnes(string s){
        for(char&c:s){
            if(c!='1') return false;
        }
        return true;
    }

    int replacedInt(string s,char oldC,char newC){

        int n=s.size();
        for(int i=0;i<n;i++){
            char c=s[i];
            if(c==oldC) s[i]=newC;
        }

        return stoi(s);
    }

    int findMax(string s){

        char toReplace;

        for(char& c:s){
            if(c!='9'){
                toReplace=c;
                break;
            }
        }

        return replacedInt(s,toReplace,'9');
    }

    int findMin(string s){

        if(allOnes(s)) return stoi(s);

        char toReplace;

        for(char& c:s){
            if(c!='1' && c!='0'){
                toReplace=c;
                break;
            }
        }

        if(s[0]=='1') return replacedInt(s,toReplace,'0');

        return replacedInt(s,toReplace,'1');
    }
public:
    int maxDiff(int num) {

        string s=to_string(num);

        int first=findMax(s);

        int second=findMin(s);

        return first-second;
        
    }
};