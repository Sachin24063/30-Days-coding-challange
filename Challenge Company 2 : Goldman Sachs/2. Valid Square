class Solution {
public:
int count_dist(vector<int> a, vector<int> b){
    return ((b[1]-a[1])*(b[1]-a[1])+(b[0]-a[0])*(b[0]-a[0]));
}
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
      vector<vector<int>> matrix = {p1,p2,p3,p4};
      set<int> n;
      for(int i=0;i<4;i++){
          for(int j=i+1;j<4;j++){
              int val = count_dist(matrix[i],matrix[j]);
              if(val!=0) n.insert(val);
              else return false;
          }
      }
    if(n.size()==2) return true;
    return false;
    }
};
