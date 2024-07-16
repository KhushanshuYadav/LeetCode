class StockSpanner {
private:
stack<pair<int,int>>s; //pair of price and its span
public:
    
    StockSpanner() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    
    int next(int price) {

        int passedPriceSpan=1;   //itself contribution in span


        while(!s.empty() && price>=s.top().first){


            passedPriceSpan+=s.top().second;     
            //see if top is lesser then its span reprsents count of all values greater than or equal to it including itself
            //so automatically all values these were be less then new greater so add it to new span


            s.pop();
        }

        s.push({price,passedPriceSpan});


        return passedPriceSpan;
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */