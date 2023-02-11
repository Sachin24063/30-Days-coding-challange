class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long m = mass;
        sort(asteroids.begin(),asteroids.end());
        for(int i=0;i<asteroids.size();i++){
            if(asteroids[i]<=m) m+=asteroids[i];
            else return false;
        }
        return true;
    }
};
