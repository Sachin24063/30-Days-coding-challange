class Solution {
public:
vector<int> bob;
int target = 0;
void solve(int n, int numsArrow,int sum, vector<int> alice, vector<int>temp){
if(n==-1 | numsArrow<=0){
if(sum > target){
    target = sum;
    if(numsArrow > 0){
        temp[0] += numsArrow;
    }
    bob = temp;
}
return;
}
if(alice[n]+1 <= numsArrow){
    temp[n] = alice[n]+1;
    solve(n-1, numsArrow-(alice[n]+1), sum+n, alice, temp);
    temp[n] = 0;
}
solve(n-1, numsArrow, sum, alice, temp);
}
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        vector<int> temp(12,0);
        solve(11, numArrows, 0, aliceArrows, temp);
        return bob;
    }
};
