class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int count=0;
        vector<int> arr = nums;
        sort(nums.begin(),nums.end());
        int i,j;
        for(i=0;i<n;i++){
            if(nums[i]!=arr[i])
            break;
        }
        for(j=n-1;j>=0;j--){
            if(nums[j]!=arr[j])
            break;
        }
        for(int k=i;k<=j;k++){
            count++;
        }
        return count;
        }
};
