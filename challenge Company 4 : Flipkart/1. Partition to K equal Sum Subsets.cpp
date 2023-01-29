class Solution {
public:
bool backtrack(vector<int>& nums, int k, int target,int  current_sum,vector<bool>& visited, int index){
    if(k == 0) return true;
    if(current_sum > target) return false;
    if(current_sum == target )
        return backtrack(nums,k-1,target,0,visited,0);
    for(int i=index;i<nums.size();i++){
        if(!visited[i]){
            visited[i] = true;
            if(backtrack(nums,k,target,current_sum+nums[i],visited,i+1)){return true;}
        visited[i] = false;
        }
    }
    return false;
}
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum =0, max_num = 0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            max_num = max(max_num,nums[i]);
        }
        if(sum %k!=0 || max_num>sum/k) return false;
        vector<bool> visited(nums.size());
        return backtrack(nums,k,sum/k,0,visited,0);
    }
};
