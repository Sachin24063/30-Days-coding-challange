class Solution {
public:
       // Function for check a cycle in graph
    bool is_cycle(vector<vector<int>>& matrix, vector<int>& visited, int curr){
        if(visited[curr]==2) return true;

        visited[curr]=2;
        for(int i=0;i<matrix[curr].size();i++){
            if(visited[matrix[curr][i]]!=1){
                if(is_cycle(matrix,visited,matrix[curr][i]))
                return true;
            }
        }
        visited[curr]=1;
        return false;
    }

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> matrix(numCourses);
    for(int i=0;i<prerequisites.size();i++){
 matrix[prerequisites[i][0]].push_back(prerequisites[i][1]);
    }
    vector<int> visited(numCourses,0);
    for(int i=0;i<numCourses;i++){
        if(visited[i]==0)
            if(is_cycle(matrix,visited,i))
                return false;
    }
    return true;
    }
};
