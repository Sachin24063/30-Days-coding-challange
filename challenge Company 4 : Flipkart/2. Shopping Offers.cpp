//Recursive Approach
class Solution {
public:
    int calculate_price(vector<int>& price, vector<int>& needs){
        int total_price = 0;
        for(int i=0;i<price.size();i++){
            total_price += price[i]*needs[i];
        }
        return total_price;
    }
    void subtract_offer(vector<int>& sp, vector<int>& needs){
        for(int i=0;i<needs.size();i++){
            needs[i] -= sp[i];
        }
    }
    bool non_negative(vector<int>& needs){
        for(int i=0;i<needs.size();i++) if(needs[i]<0) return false;
        return true;
    }
    void add_offer(vector<int>& sp, vector<int>& needs){
        for(int i=0;i<needs.size();i++){
            needs[i] += sp[i];
        }
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int best_price = calculate_price(price,needs);
        for(auto& sp: special){
            subtract_offer(sp,needs);
            if(non_negative(needs)){
                int withoffer = sp.back() + shoppingOffers(price, special,needs);
                best_price = min(best_price, withoffer);
            }
        add_offer(sp, needs);
        }
    return best_price;
    }
};

//It Will Gives TLE on 64/65 Test case

for avoiding a TLE we use Dynamic Programming

// DP Approach
class Solution {
public:
bool noNegatives(vector<int>& needs) {
        for (int i=0;i<needs.size();i++){
           if(needs[i]<0)
                return false;
        }
        return true;
}
map<vector<int>, int> mp;
        int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
    if(mp[needs]>0){
        return mp[needs];
    }
    int minimum = 0;
    for(int i=0;i<needs.size();i++){
        minimum += needs[i]*price[i];
    }
    for(auto sp: special){
        vector<int> n = needs;
        for(int i=0;i<n.size();i++){
            n[i]-=sp[i];
        }
        if(noNegatives(n)){
            minimum = min(minimum,sp[sp.size()-1] + shoppingOffers(price,special,n));
        }
    }
    return mp[needs] = minimum;
    }
};
