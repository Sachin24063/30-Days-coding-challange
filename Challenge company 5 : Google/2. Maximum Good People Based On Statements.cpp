class Solution {
public:
int n = 0;
int ans = 0;
int maximumGood(vector<vector<int>>& statements) {
        n = statements.size();
       string curr = "";
       combination(statements, curr,0,0);
    return ans;
    }

void combination(vector<vector<int>> &statments, string &curr, int idx, int count){
    //in this function we create all combination of size n
    if(idx == n){
        if(is_safe(curr, statments)) ans = max(ans, count);
        return;
    }
    curr.push_back('1');
    combination(statments, curr, idx+1, count+1);

    curr.back() = '0';
    combination(statments, curr, idx+1, count);

    curr.pop_back();
}

bool is_safe(string &curr, vector<vector<int>> &statments){
    //in this function we only care about what good person are   say.
    for(int i=0;i<n;i++){
        if(curr[i] == '1'){
            for(int j=0;j<n;j++){
            if(statments[i][j]!=2 && statments[i][j] != 
                curr[j]-'0') return false;
        }
        }
    }
return true;
}
};
