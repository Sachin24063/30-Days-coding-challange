class Solution {
public:
bool is_valid(int i, int j, int n, int m, vector<vector<int>>& grid){
   if(i>=0 && j>=0 && i<n && j<m && grid[i][j]==0) return true;
   return false;
}
 void make_boundry_zero(int i, int j, int n, int m, vector<vector<int>>& grid){
     if(is_valid(i,j,n,m,grid)){
         grid[i][j] = 1;
            make_boundry_zero(i+1,j,n,m,grid);
             make_boundry_zero(i-1,j,n,m,grid);
              make_boundry_zero(i,j+1,n,m,grid);
               make_boundry_zero(i,j-1,n,m,grid);
     }
        }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i*j == 0 || i == n-1 || j==m-1){
                    make_boundry_zero(i,j,n,m,grid);
                }
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    make_boundry_zero(i,j,n,m,grid);
                    ans++;
                }
            }
        }
        return ans;
        }
};
