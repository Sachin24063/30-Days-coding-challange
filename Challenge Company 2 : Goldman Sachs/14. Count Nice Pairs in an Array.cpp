class Solution {
public:
int mod = 1e9+7;
int rev(int n){
    int rem = 0, rev_ans = 0;
    while(n!=0){
        rem = n%10;
        rev_ans = rev_ans*10+rem;
        n/=10;
    }
    return rev_ans;
}
    int countNicePairs(vector<int>& nums) {
        long long count = 0;
        unordered_map<int, int> mp;
        for(int i=0;i<nums.size();i++){
            int temp = (nums[i] - rev(nums[i]));
            mp[temp]++;
            count = count+mp[temp]-1 % mod;
        }
    return count%mod;
    }
};
