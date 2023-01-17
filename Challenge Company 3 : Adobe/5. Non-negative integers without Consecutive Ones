class Solution {
public:
    int findIntegers(int n) {
        // DP approach in O(32) Time complexity
        // this problem is solved excectly same as fibonacci series
        vector<int> dp(32), dpone(32), dpzero(32);
        dpzero[0] = dp[0] = 1;
        for(int i=1; i<32;i++){
            dpone[i] = dpzero[i-1];
            dpzero[i] = dpone[i-1] + dpzero[i-1];
            dp[i] = dpone[i] + dpzero[i];
        }
        int ans = 0, last_bit = -1;
        for(int k = 30; k>=0;k--){
            int bit = (n >> k) & 1;
            if (bit == 1){
                ans += dp[k];
                if(last_bit == 1) return ans;
            }
            last_bit = bit;
        }
        return ans+1; // 1 for n itself
    }
};
