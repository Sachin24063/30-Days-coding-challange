class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
       unordered_set<string> visited;
       queue<string> q;
       q.push(startGene);
       visited.insert(startGene);
       int count = 0;
       while(!q.empty()) {
           int n = q.size();
           for(int i=0;i<n;i++){
               string node = q.front();
               q.pop();

               if(node == endGene){
                   return count;
               }
               for(char ch : "ACGT"){
                   for(int j=0;j<node.size();j++){
                       string adj_node = node;
                       adj_node[j] = ch;
                       if(!visited.count(adj_node) && find(bank.begin(),bank.end(),adj_node) !=bank.end()){
                           q.push(adj_node);
                           visited.insert(adj_node);
                       }
                   }
               }
           }
           count++;
       }
    return -1;
    }
};
