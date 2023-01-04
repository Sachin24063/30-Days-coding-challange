// Language : C++

Approach -> Backtracking

class Solution {
public:
    vector<vector<int>> ans;
    void solve(int st, int k, int n,vector<int> arr){
        if(k == arr.size()) {
            if(n==0){
            ans.push_back(arr);
            return;
            }
        }
        for(int i=st;i<=9;i++){
            arr.push_back(i);
            solve(i+1,k,n-i,arr);
            arr.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> arr;
        solve(1,k,n,arr);
        return ans;
    }
};
