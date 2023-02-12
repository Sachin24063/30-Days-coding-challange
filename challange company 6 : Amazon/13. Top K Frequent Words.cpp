class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
   map<string, int> mp;
     for(auto it: words){ 
         mp[it]++;
     }  
     vector<pair<int,string>> vp;
     for(auto it: mp){
         vp.push_back({it.second, it.first});
     } 
     auto l = [](pair<int,string>&p1, pair<int,string>&p2){
         if(p1.first == p2.first) return p1.second<p2.second;
         return p1.first>p2.first;
     };
    sort(vp.begin(),vp.end(),l);
    vector<string> ans;
    for(int i=0;i<k;i++){
        ans.push_back(vp[i].second);
    }
    return ans;
    }
};
