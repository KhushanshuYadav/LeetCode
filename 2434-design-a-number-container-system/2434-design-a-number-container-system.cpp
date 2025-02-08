class NumberContainers {

    unordered_map<int,int>iToN; //index,number
    unordered_map<int,priority_queue<int, vector<int>, greater<int>>>nToI; //number,indexSet
public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {

       

        iToN[index]=number;

        nToI[number].push(index);

        


        
    }
    
    int find(int number) {

        if(!(nToI.count(number))) return -1;

        auto& pq=nToI[number];

        while(!pq.empty()){
            int i=pq.top();

            if(number==iToN[i]) return i;

            pq.pop();


        }

        return -1;
        
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */