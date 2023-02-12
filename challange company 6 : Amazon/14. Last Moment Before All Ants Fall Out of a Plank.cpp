class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int mn =n, mx=0;
        for(int i=0;i<left.size();i++){
            mx = max(mx,left[i]);
        }
        for(int i=0;i<right.size();i++){
            mn = min(mn,right[i]);
        }
        return max(mx, n-mn);   
    }
};
