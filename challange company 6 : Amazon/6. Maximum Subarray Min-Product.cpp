class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
       vector<long> prefix_sum(nums.size()+1);
       prefix_sum[0] = 0;
       for(int i=0;i<nums.size();i++){
           prefix_sum[i+1] = prefix_sum[i]+nums[i];
       }
       stack<long> st;
       long ans =0;
       for(int i=0;i<=nums.size();i++){
           while(!st.empty() && (i==nums.size() || nums[st.top()]>nums[i])){
               int j=st.top();
               st.pop();
               long temp = 
               ans = max(ans,(long)nums[j]*(prefix_sum[i] - prefix_sum[st.empty() ? 0 : st.top()+1]));
           }
           st.push(i);
       }
       int mod = 1e9+7;
       return ans%mod;
    }
};
