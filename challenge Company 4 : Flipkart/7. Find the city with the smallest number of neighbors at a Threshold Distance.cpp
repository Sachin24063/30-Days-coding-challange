class Solution {
public:
// esiest solution using flayed warshall algorithm 
// Time complexity for flayed warshall is O(n^3)
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold){
        vector<vector<int>> fd(n, vector<int>(n, INT_MAX));
        for(auto it : edges){
            fd[it[0]][it[1]] = it[2];
            fd[it[1]][it[0]] = it[2];
        }
        for(int i=0;i<n;i++) fd[i][i] = 0;
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(fd[i][k] == INT_MAX || fd[k][j] == INT_MAX) continue;
                        fd[i][j] = min(fd[i][j],fd[i][k]+fd[k][j]);
                }
            }
        }
        int city = -1, cnt = n;
        for(int i=0;i<n;i++){
            int cnt_n = 0;
            for(int k=0;k<n;k++){
                if(fd[i][k]<=distanceThreshold) cnt_n++;
            }
           if(cnt_n <= cnt){
               city = i;
               cnt = cnt_n;
           }
        }
        return city;
    }
};
