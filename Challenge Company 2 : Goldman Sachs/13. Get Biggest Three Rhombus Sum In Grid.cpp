class Solution {
public:
bool check_range(int i,int j,int m,int n){
    return i>=0 && i<m && j>=0 && j<n;
}
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        set<int> st;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                st.insert(grid[i][j]);
            }
        }
        for(int i=1;i<=50;i++){
            for(int j=0;j<m;j++){
                for(int k=0;k<n;k++){
                    if(check_range(j-i,k,m,n) && check_range(j,k-i,m,n) && check_range(j+i,k,m,n) && check_range(j,k+i,m,n)){
                        int sum = grid[j-i][k] + grid[j+i][k] + 
                        grid[j][k-i] + grid[j][k+i];

                        for(int x=1;x<i;x++){
                            sum+=grid[j-x][k+i-x];
                        }
                        for(int x=1;x<i;x++){
                            sum+=grid[j+x][k+i-x];
                        }
                        for(int x=1;x<i;x++){
                            sum+=grid[j-x][k-i+x];
                        }
                        for(int x=1;x<i;x++){
                            sum+=grid[j+x][k-i+x];
                        }
                        st.insert(sum);
                    }
                }
            }
        }
        vector<int> ans;
        for(auto i: st) ans.push_back(i);
        reverse(ans.begin(),ans.end());
        vector<int> final_ans;
        if(ans.size()<3) return ans;
        for(int i=0;i<3;i++){
            final_ans.push_back(ans[i]);
        }
        return final_ans;
    }
};
