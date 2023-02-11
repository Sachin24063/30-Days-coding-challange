class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> D;
        queue<int> R;
        int n = senate.size(),i=0;
        for(auto it: senate){
            if(it == 'D') D.push(i);
            else R.push(i);
            i++;
        }
        while(!R.empty() && !D.empty()){
            if(R.front() < D.front()){
                D.pop();
                R.push(R.front() + n);
                R.pop();
            }
            else{
                R.pop();
                D.push(D.front() + n);
                D.pop();
            }
        }
        if(R.empty()) return "Dire";
        return "Radiant";
    }
};
