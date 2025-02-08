class NumberContainers {

    unordered_map<int,int>iToN; //index,number
    unordered_map<int,set<int>>nToI; //number,indexSet
public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {

        if(iToN.count(index)){

            int n=iToN[index];
            cout<<"n "<<n<<endl;

            auto& s= nToI[n];

            s.erase(index);
            if(s.empty()) nToI.erase(n);
        }

        iToN[index]=number;

        nToI[number].insert(index);

        


        
    }
    
    int find(int number) {

        if(!(nToI.count(number))) return -1;

        int ans=*(nToI[number].begin());

        return ans;
        
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */