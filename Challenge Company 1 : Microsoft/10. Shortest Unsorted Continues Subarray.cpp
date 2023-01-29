class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int Max=nums[0],end=-1;
        for(int i=1;i<n;i++){
            if(Max>nums[i]) end = i;
            else Max=nums[i];
        }
        int Min=nums[n-1],start=0;
        for(int i=n-2;i>=0;i--){
            if(nums[i]>Min) start=i;
            else Min=nums[i];
         }    
        return end-start+1;
        }
};
