class Solution {
public:
    string longestPrefix(string s) {
      // DP approach
       int i=0,j=1,n=s.size();
       vector<int> ans(n);
       for(;j<n;){
           if(s[i]==s[j]){
               ans[j]= i+1;
               j++;
               i++;
           }
           else if(i) i = ans[i-1];
           else j++;
       } 
    string str = s.substr(0,i);
    return str;
    }
};
