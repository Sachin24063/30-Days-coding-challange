class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(auto it: flights){
            adj[it[0]].push_back({it[1], it[2]});
        }
        //for this question we don't take the priority queue.
        queue<pair<int, pair<int,int>>> q;
        q.push({0,{src,0}});
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        //dijkstra algorithm
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;//because the structure of queue is {stops, {node, cost}}
            int cost = it.second.second;
            if(stops> k) continue;
            for(auto iter: adj[node]){
                int adjnode = iter.first;
                int edw = iter.second;
                if(cost+edw < dist[adjnode] && stops<=k){
                    dist[adjnode] = cost+edw;
                    q.push({stops+1,{adjnode, cost+edw}});
                }
            }
        }
        if(dist[dst] == 1e9) return -1;
        return dist[dst];
    }
};
