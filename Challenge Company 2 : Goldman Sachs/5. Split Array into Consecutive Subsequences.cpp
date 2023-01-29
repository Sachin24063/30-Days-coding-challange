class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int n=nums.size();
        map<int, int> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        map<int, int> extra;
        for(int i=0;i<n;i++){
            if(mp[nums[i]]==0) continue;
            mp[nums[i]]--;

            if(extra[nums[i]-1]>0){
                extra[nums[i]-1]--;
                 extra[nums[i]]++;
            }

            else if(mp[nums[i]+1]>0 && mp[nums[i]+2]>0){
                mp[nums[i]+1]--;
                mp[nums[i]+2]--;
                extra[nums[i]+2]++;
            }
            else return false;
        }
        return true;
    }
};
