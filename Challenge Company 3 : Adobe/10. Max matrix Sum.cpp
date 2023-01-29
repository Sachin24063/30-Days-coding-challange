class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long int sum = 0;
        int n = matrix.size();
        int val = INT_MAX;
        int neg_count = 0;
        for(int i =0;i<n;i++){
            for(int j=0;j<n;j++){
                val = min(val, abs(matrix[i][j]));
                if(matrix[i][j]<0) {neg_count++;}
                sum+=abs(matrix[i][j]);
            }
        }
        if(neg_count%2 == 0){
            return sum;
        }
        return sum-2*(val);
    }
};
