class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if(k==0 || n>= k+maxPts) return 1.0;
    vector<double> dp(n+1,0.0);
    dp[0] = 1.0;
    double running_sum = dp[0];
    double ans = 0.0;
    for(int i=1;i<=n;i++){
        dp[i] = running_sum/(double)maxPts;
        //here we remove the one sum from teil end and adding the one running sum from front end.
        if(i<k){//here we handles the value which can below the threshold k
        running_sum+=dp[i];
        }
        else {ans+=dp[i];}
        if(i-maxPts>=0){
            running_sum -= dp[i-maxPts];
        }
    }
    return ans;
    }
};
