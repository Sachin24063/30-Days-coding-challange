class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        map<pair<int, int>,int> v;
        for(vector<int>& i: rectangles){
            v[{i[0], i[1]}]++;
            v[{i[0], i[3]}]--;
            v[{i[2], i[1]}]--;
            v[{i[2], i[3]}]++;
        }
    int N=0;
    for(auto i=v.begin();i!=v.end();i++){
        if(i->second!=0){
            if(abs(i->second)!=1){
                return false;
            }
            N++;
        }
    }
    return N==4;
    }
};

Time Complexity = O(n log n)
