class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> matrix(n+1);
        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=0;i<times.size();i++){
             matrix[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        for(int i=0;i<matrix.size();i++){
            cout<<i<<"->";
            for(int j=0;j<matrix[0].size();j++){
                cout<<matrix[i][j].first<<"-"<<matrix[i][j].second<<" ";
            }
            cout<<endl;
        }
        vector<int> dist(n+1, 1e9);
        dist[0] = 0;
        pq.push({0,k});
        dist[k] = 0;
        while(!pq.empty()){
            auto it= pq.top();
            pq.pop();
            int t = it.first;
            int node = it.second;
            cout<<node<<" "<<t<<" ";

            for(auto x:matrix[node]){
               int adjNode = x.first;
                int wt = x.second;
                int curr = wt + t;
                if(curr<dist[adjNode])  {
                    dist[adjNode] = curr;
                    pq.push({curr,adjNode});
                }
            }
        }
        if(*max_element(dist.begin(),dist.end())!=1e9)
            return *max_element(dist.begin(),dist.end());
        else
        return -1;
    }
};
