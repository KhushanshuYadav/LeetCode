class Solution {
public:
    vector<int> twoSum(vector<int>& book, int k) {
        unordered_map<int,int>s;
        int n=book.size();
        vector<int>v;
    

    for(int i=0;i<n;i++){
        
        if(s.find(k-book[i])!=s.end()){
            v.push_back(i);
            v.push_back(s[k-book[i]]);
        }
        s[book[i]]=i;

    }

    return v;
    }
};