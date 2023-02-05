class Solution {
public:
    int query(vector<vector<int>>& dp, int si, int sj, int ei, int ej){
        if(si==0 && sj!=0){
            return dp[ei][ej] - dp[ei][sj-1];
        }
        else if(si!=0 && sj==0){
            return dp[ei][ej]-dp[si-1][ej];
        }
        else if(si==0 && sj==0){
            return dp[ei][ej];
        }
        else {
            return dp[ei][ej] - dp[ei][sj-1] - dp[si-1][ej] + dp[si-1][sj-1];
        }
        return 0;
    }
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int mod = 1e9 + 7;
        int n = mat.size(),m=mat[0].size();
        vector<vector<int>> dp(n, vector<int>(m));
        dp[0][0] = mat[0][0] % mod;
        for(int i=1;i<n;i++){
            dp[i][0] = (dp[i-1][0] + mat[i][0]) % mod;
        }
        for(int i=1;i<m;i++){
            dp[0][i] = (dp[0][i-1] + mat[0][i]) % mod;
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                dp[i][j] = ((dp[i-1][j]+dp[i][j-1]+mat[i][j])-dp[i-1][j-1]+mod)%mod;
            }
        }
        vector<vector<int>> ans(n, vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int si = max(0,i-k);
                int sj = max(0,j-k);
                int ei = min(n-1,i+k);
                int ej = min(m-1,j+k);
                ans[i][j] = query(dp,si,sj,ei,ej);
            }
        }
        return ans;
    }
};
