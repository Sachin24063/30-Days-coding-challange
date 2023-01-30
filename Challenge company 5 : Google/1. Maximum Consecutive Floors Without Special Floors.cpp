class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        int n= special.size();
        int ans = 0;
        sort(special.begin(),special.end());
        int first = max(special[0]-bottom, top - special[n-1]);
        ans = max(ans,first);
        for(int i=1;i<n;i++){
            ans = max(ans, (special[i]-special[i-1])-1);
        }
        return ans;
    }
};
