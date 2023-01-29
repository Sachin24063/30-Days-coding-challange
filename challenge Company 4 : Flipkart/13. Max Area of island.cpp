class Solution {
public:
int is_island(vector<vector<int>>& grid, int i, int j, int& count, int m, int n){
    if(i<0 || j<0 || i>=m || j>=n) return 0;
    if(grid[i][j] == 0) return 0;
    grid[i][j] = 0;
    if(is_island(grid, i-1, j, count, m, n)) count++;
    if(is_island(grid, i+1, j, count, m, n)) count++;
    if(is_island(grid, i, j-1, count, m, n)) count++;
    if(is_island(grid, i, j+1, count, m, n)) count++;

    return count;
}
    int maxAreaOfIsland(vector<vector<int>>& grid) {
       int m = grid.size();
       int n = grid[0].size();
       int ans = 0;
       for(int i=0;i<m;i++){
           for(int j=0;j<n;j++){
               int count = 1; // for the own cell has value 1
               if(grid[i][j] == 1){
                   is_island(grid, i, j, count, m, n);
                   ans = max(ans, count);
               }
           }
       }
    return ans;
    }
};
