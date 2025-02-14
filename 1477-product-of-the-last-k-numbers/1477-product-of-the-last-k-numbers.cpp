class ProductOfNumbers {
    vector<int>list;
    int n;
public:
    ProductOfNumbers() {

        this->n=0;
        
    }
    
    void add(int num) {
        n++;
        list.push_back(num);
        
    }
    
    int getProduct(int k) {

        int product=1;
        int i=n-1;
        while(k--){
            product*=(list[i]);
            i--;
        }

        return product;
        
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */