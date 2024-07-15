class Solution {
public:
    vector<int> twoSum(vector<int>& book, int k) {
        unordered_map<int,int>m;
        int n=book.size();
        vector<int>v;
    

    for(int i=0;i<n;i++){
        
        if(m.find(k-book[i])!=m.end()){
            v.push_back(i);
            v.push_back(m[k-book[i]]);
            break;
        }
        m[book[i]]=i;

    }

    return v;
    }
};