class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        //dynamic programming approach
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<vector<int>> dp(m,vector<int>(n));
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i==m-1 && j==n-1) { dp[i][j]=min(0,dungeon[i][j]);} //bootom right cell or princess cell
                else if(i==m-1) //for the last row we move only right
                dp[i][j]=min(0,dungeon[i][j]+dp[i][j+1]);
                else if(j==n-1)// for last column we move only bottom side
                dp[i][j]=min(0,dungeon[i][j]+dp[i+1][j]);
                else
               dp[i][j]=min(0,dungeon[i][j]+max(dp[i][j+1],dp[i+1][j]));
            }
        }
        return abs(dp[0][0])+1;
    }
};
