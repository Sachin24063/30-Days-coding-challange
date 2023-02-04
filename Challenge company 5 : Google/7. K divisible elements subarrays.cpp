class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
      unordered_set<string> st;
      for(int i =0;i<nums.size();i++){
          for(int j=i;j<nums.size();j++){
              string str; int temp = 0;
              for(int l=i;l<=j;l++){
                  str.push_back(nums[l]);
                  if(nums[l] % p == 0){ temp++;
                  }
                  if(temp > k) break;
              }
              if(temp<=k) st.insert(str);
          }
      }
    return st.size();
    }
};
