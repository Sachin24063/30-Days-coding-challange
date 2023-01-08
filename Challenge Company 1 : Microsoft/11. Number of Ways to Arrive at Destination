Approach: Dijkstra Algorithm

class Solution {
public:
typedef long long ll;
    int countPaths(int n, vector<vector<int>>& roads) {
       //creating a graph
       vector<pair<int,int>> matrix[n];
       for(auto x: roads){
           matrix[x[0]].push_back({x[1],x[2]});
           matrix[x[1]].push_back({x[0],x[2]});
       }
       //now use the dijkstra algorithm
       //for dijkstra algorithm define a priority queue
       priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll,ll>>> pq;
       vector<ll> dist(n, LONG_MAX), ways(n,0);
       //vector<long long int> ways(n,0);
        //initial distance is 0
        dist[0]=0;
        //ways to reach starting node is just 1
        ways[0]=1;
        pq.push({0,0});
        ll mod = 1e9 + 7;
        while(!pq.empty()){
            ll dis = pq.top().first;
            ll node = pq.top().second;
            pq.pop();

            for(auto it: matrix[node]){
                ll adj_node = it.first;
                ll adj_weight = it.second;

                if(dis + adj_weight < dist[adj_node]){
                    dist[adj_node] = dis + adj_weight;
                    pq.push({dis+adj_weight, adj_node});
                    ways[adj_node] = ways[node];
                }
                // if same path
                else if(dis+adj_weight == dist[adj_node]){
                    ways[adj_node] = (ways[adj_node] + ways[node])%mod;
                }
            }
        }
    return ways[n-1];
    }
};
