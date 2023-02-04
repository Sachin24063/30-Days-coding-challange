class Solution {
public:
vector<int> sum;
    Solution(vector<int>& w) {
        sum.push_back(w[0]);
       for(int i=1;i<w.size();i++){
           sum.push_back(sum[i-1]+w[i]);
       }
    }
    int pickIndex() {
        int first = sum.back(), rand_idx = rand()%first;
        auto it = upper_bound(sum.begin(),sum.end(),rand_idx);
        return it-sum.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
