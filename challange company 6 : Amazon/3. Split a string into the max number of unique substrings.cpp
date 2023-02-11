class Solution {
public:
    unordered_set<string> st;
    int backtrack(string s, int idx){
        if(idx >= s.size()) return 0;
        int ans =0;
        for(int i=idx;i<s.size();i++){
            string temp = s.substr(idx, i-idx+1);
            if(st.find(temp) == st.end()){
                st.insert(temp);
                ans = max(ans, 1+backtrack(s,i+1));
                st.erase(temp);
            }
        }
        return ans;
    }
    int maxUniqueSplit(string s) {
        return backtrack(s, 0);
    }
};
