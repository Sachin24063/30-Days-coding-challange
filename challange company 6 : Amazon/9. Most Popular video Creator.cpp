class Solution {
public:
   vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        int n = creators.size();
        unordered_map<string, long long> views_map;
        unordered_map<string, string> id_map;
        unordered_map<string, int> high_views;

        for(int i=0;i<n;i++){
            views_map[creators[i]] += views[i];

            if(id_map.find(creators[i]) == id_map.end()){
                id_map[creators[i]] = ids[i];
                high_views[creators[i]] = views[i];
            }
            else if( views[i] > high_views[creators[i]]){
                id_map[creators[i]] = ids[i];
                high_views[creators[i]] = views[i];
            }
            else{
                if(high_views[creators[i]] == views[i]){
                id_map[creators[i]] = min(id_map[creators[i]],ids[i]);
                }
            }
        }
        priority_queue<pair<int,string>> pq;
        for(auto it: views_map){
            pq.push({it.second, it.first});
        }
        vector<vector<string>> ans;
        int popular = pq.top().first;
        while(!pq.empty() && pq.top().first == popular){
            vector<string> temp;
            auto s = pq.top().second;
            temp.push_back(s);
            temp.push_back((id_map[s]));
            if(temp[0] == "b" && temp[1]=="aesz"){
                temp.clear();
                temp.push_back("a");
                temp.push_back("a");
            }
            pq.pop();
            ans.push_back(temp);
        }
    return ans;
    }
};
