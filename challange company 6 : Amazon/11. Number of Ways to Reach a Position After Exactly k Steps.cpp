class Solution {
public:
int mod = 1e9+7;
    int solve(int s, int e, int curr, int k, vector<vector<int>>&dp){
        if(k == 0){
            if(curr == e) return 1;
            else return 0;
        }
        if(dp[curr+1001][k] != -1) return dp[curr+1001][k];
        int right_moves = solve(s, e, curr+1, k-1, dp) % mod;
        int left_moves = solve(s, e, curr-1, k-1, dp) % mod;

        return dp[curr+1001][k] = (right_moves + left_moves) % mod ;
    }
    int numberOfWays(int startPos, int endPos, int k) {
        vector<vector<int>> dp(3002, vector<int>(1001, -1));
        return solve(startPos, endPos, startPos, k, dp);
    }
};
