// sliding window approach
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
     int m = nums1.size();
     int n = nums2.size();
     int ans = 0;
     for(int i=-n+1;i<m;i++){
         int cnt =0;
        for(int j=0;j<n;j++){
            if(i+j<0) {continue;}
            else if(i+j >= m){ break;}
            else if(nums1[i+j] == nums2[j]){
                cnt++;
                ans = max(cnt, ans);
            }
            else {cnt =0;}
        }
     } 
     return ans;  
    }
};

//Dynamic Programming Approach
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int ans = 0;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    ans = max(ans, dp[i][j]);
                }
            }
        }

        return ans;
    }
};
