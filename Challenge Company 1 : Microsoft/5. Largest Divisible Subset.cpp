class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
       int n= nums.size();
        sort(nums.begin(),nums.end());
        int max_i = 1, end_index=0;
        vector<int> dp(n,1), hash(n);
        for(int i=0;i<n ;i++){
            hash[i] = i;
            for(int prev=0;prev<i;prev++){
                if(nums[i] % nums[prev]==0 && 1+dp[prev]>dp[i]){
                    dp[i] = 1+dp[prev];
                    hash[i] = prev;
                }
            }
            if(dp[i]>max_i){
                max_i = dp[i];
                end_index = i;
            }
        }
       vector<int> ans;
       ans.push_back(nums[end_index]);
       while(hash[end_index] != end_index){
           end_index = hash[end_index];
           ans.push_back(nums[end_index]);
       }  
       reverse(ans.begin(),ans.end());
       return ans;
    }
};
