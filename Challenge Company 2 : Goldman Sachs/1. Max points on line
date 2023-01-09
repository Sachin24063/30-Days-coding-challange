class Solution {
public:
    int maxPoints(vector<vector<int>>& arr) {
        int n = arr.size();
        if(n<=2) return n;
        //for x1 y1
        int final_count=2;
        for(int i=0;i<n;i++){
            //for x2 y2
            for(int j=i+1;j<n;j++){
                int total=2;
                //for x3 y3
                for(int k=0;k<n;k++){
                    if(k!=i & k!=j){
        if((arr[j][1]-arr[i][1])*(arr[k][0]-arr[i][0]) == (arr[j][0]-arr[i][0])*(arr[k][1]-arr[i][1])) total++;
                
                }
                }
            final_count=max(final_count,total);
            }
        }
    return final_count;
    }
};
