class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        map<int, int> mp; 
        for(auto it: barcodes){
            mp[it]++;
        }
        vector<pair<int,int>> vp;
        for(auto it: mp){
            vp.push_back({it.second,it.first});
        }
        sort(vp.rbegin(),vp.rend());
        vector<int> ans(barcodes.size()),temp;
        for(auto it: vp){
            for(int i=0;i<it.first;i++){
                temp.push_back(it.second);
            }
        }
        int k=0;
        for(int i=0;i<barcodes.size();i+=2){
            ans[i]=temp[k++];
        }
        for(int i=1;i<barcodes.size();i+=2){
            ans[i]=temp[k++];
        }
        return ans;
    }
};
