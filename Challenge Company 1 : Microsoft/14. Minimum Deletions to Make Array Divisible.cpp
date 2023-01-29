class Solution {
public:
    int Find_GCD(vector<int> nums){
        int gcd = nums[0];
        for (int i=1;i<nums.size();i++){
            int num = nums[i];
            while(num>0){
                int temp = gcd%num;
                gcd = num;
                num = temp;
            }
        }
        return gcd;
    }
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        sort(nums.begin(),nums.end());
        int gcd=Find_GCD(numsDivide);
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(gcd%nums[i]==0) return i;
        }
   return -1;
    }
};
