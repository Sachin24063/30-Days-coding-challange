class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        for(auto i : queries){
            vector<pair<string, int>> vp;
            for(int j=0;j<nums.size();j++){
                string sub = nums[j].substr(nums[j].size()-i[1]);
                vp.push_back({sub,j});
            }
            sort(vp.begin(),vp.end());
            int k = i[0]-1;
            ans.push_back(vp[k].second);
        }
        return ans;
    }
};
