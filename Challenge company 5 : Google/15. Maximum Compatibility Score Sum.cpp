	class Solution {
	public:
    int solve(int i,
    vector<vector<int>>&students,vector<vector<int>>&mentors,vector<int>&visited)
    {
        if(i>=students.size())
            return 0;
        
        int maxi=0;
        for(int j=0;j<mentors.size();j++){
            if(visited[j]==0){
                visited[j]=1;
                int match=0;
                for(int k=0;k<students[i].size();k++){
                    if(students[i][k]==mentors[j][k])
                        match++;
                }
                int score= match + solve(i+1,students,mentors,visited);
                maxi=max(maxi,score);
                visited[j]=0;
            }
        }
        return maxi;
    }
    
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        
        int m=students.size();
        vector<int>visited(m,0);
        return solve(0,students,mentors,visited);
    }
};
