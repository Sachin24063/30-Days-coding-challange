class Solution {
public:
vector<int>old_arr; int n = 0; vector<int>new_arr;
    Solution(vector<int>& nums) {
        n= nums.size();
        old_arr = new_arr = nums;
        //new_arr = nums;
    }
    
    vector<int> reset() {
        return old_arr;
    }
    
    vector<int> shuffle() {
        for(int i=0;i<n;i++){
        int rand_index = rand()%n;
        swap(new_arr[i],new_arr[rand_index]);
        }
        return new_arr;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
