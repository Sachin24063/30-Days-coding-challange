	class Solution {
	public:
    int solve(int idx,vector<vector<int>>& students, vector<vector<int>>&mentors,vector<bool>& visited){
        if(idx>=students.size()) return 0;
        int max_ans = 0;
        for(int i=0;i<mentors.size();i++){
            if(visited[i]==true){
                visited[i] = false;
                int temp = 0;
                for(int j=0;j<students[idx].size();j++){
                    if(students[idx][j] == mentors[i][j])
                        temp++;
                }
                int max_score = temp+solve(idx+1,students,mentors,visited);
                        max_ans = max(max_ans, max_score);
                         visited[i] = true;s
            }
        }
        return max_ans;
    }
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int m=students.size();
        vector<bool>visited(m,true);
        return solve(0,students,mentors,visited);
    }
};
