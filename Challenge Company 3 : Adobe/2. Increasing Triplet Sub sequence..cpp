class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int left = INT_MAX, right = INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>right) {return true;}
            else if(nums[i]>left && nums[i]<right){
                right = nums[i];
            }
            else if(nums[i]<left){
                left = nums[i];
            }
        }
    return false;
    }
};
