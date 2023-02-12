class Solution {
public:
    double r,x,y;
        
    Solution(double radius, double x_center, double y_center) {
        r = radius, x = x_center, y = y_center;
    }
    double rand_no(){
        return (double)rand()/RAND_MAX;
    }
    vector<double> randPoint() {
        vector<double> ans;
        double len = sqrt(rand_no())*r;
        double deg = 2*3.141592653589793238*rand_no();

        ans.push_back(x+len*cos(deg));
        ans.push_back(y+len*sin(deg));
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */
