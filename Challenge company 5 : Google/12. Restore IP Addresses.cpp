class Solution {
public:
    bool is_valid(string s){
        int len = s.size();
        if(len == 1) return true;
        if(len>3 || s[0]=='0') return false;
        int num = stoi(s);
        if(num>255) return false;
        return true;
    }
    void helper(string temp, vector<string>& ans, int i, int partition, string s){
        if(i == s.size() && partition == 4){
            ans.push_back(temp.substr(0,temp.size()-1));
            return;
        }
        else if(s.size()==i || partition == 4){
            return;
        }
    helper(temp+s[i]+'.',ans, i+1, partition+1,s);
    if(s.size()>i+1 && is_valid(s.substr(i,2))){
         helper(temp+s.substr(i,2)+'.',ans, i+2, partition+1,s);
    }
    if(s.size()>i+2 && is_valid(s.substr(i,3))){
         helper(temp+s.substr(i,3)+'.',ans, i+3, partition+1,s);
    }
    }
    vector<string> restoreIpAddresses(string s) {
       vector<string> ans;
       if(s.size()>12 || s.size()<4) return ans;
       string temp; //for store the valid ip addreses
       helper(temp,ans,0,0,s);
       return ans; 
    }
};
