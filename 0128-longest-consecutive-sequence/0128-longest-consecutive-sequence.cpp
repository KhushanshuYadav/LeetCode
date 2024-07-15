class Solution {
public:
    int longestConsecutive(vector<int>&a) {
        int n=a.size();
    if(n==0){
        return 0;
    }
    
    unordered_set<int>s;
    for(auto i:a){
        s.insert(i);

    }

    int currLen=0,maxLen=1;

    for(auto i: s){
        if(s.find(i-1)==s.end()){ //means i starts new subsequence as i-1 is not existing
        currLen=1;
       
        while(s.find(i+1)!=s.end()){
            currLen++;
            i++;
        }

        maxLen=max(maxLen,currLen);

        }
    }

    return maxLen;
    }
};