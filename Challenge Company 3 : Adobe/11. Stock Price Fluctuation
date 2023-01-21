class StockPrice {
public:
    unordered_map <int, int> timestamp_to_pricemap;
    multiset<int> priceset;// multiset for store the all duplicate values
    int letest_time_stamp;
    StockPrice() {
        timestamp_to_pricemap.clear();
        priceset.clear();
        letest_time_stamp = 0;
    }
    
    void update(int timestamp, int price) {
        if(timestamp_to_pricemap.count(timestamp)){
            int old_price = timestamp_to_pricemap[timestamp];
            priceset.erase(priceset.find(old_price));
        }
        timestamp_to_pricemap[timestamp] = price;
        priceset.insert(price);

        letest_time_stamp = max(letest_time_stamp,timestamp);
    }
    
    int current() {
        return timestamp_to_pricemap[letest_time_stamp];
    }
    
    int maximum() {
        return *priceset.rbegin(); // renegin means first element from last
    }
    
    int minimum() {
         return *priceset.begin();
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
