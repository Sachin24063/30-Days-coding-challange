class Solution {
public:
    string customSortString(string order, string s) {
        map<char,int> mp;
        for(auto it: s) mp[it]++; 
        string ans = "";
        for(auto it: order){
            if(mp.find(it)!=mp.end()){
                auto temp = mp.find(it);
                string s_n(temp->second,it);
                ans+=s_n;
                mp.erase(it);
            }
        }
        for(auto it: mp){
            string s_n(it.second,it.first);
            ans+=s_n;
        }
        return ans;
    }
};
