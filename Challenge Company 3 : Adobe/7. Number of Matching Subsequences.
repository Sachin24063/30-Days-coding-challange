class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        map<char, vector<int>> mp;
        int i=0;
        for(auto x: s){
            mp[x].push_back(i++);
        }
        int ans = 0;
    for(int i=0; i<words.size();i++){
        string curr_word = words[i];
        int latest = -1;
        for(int j=0;j<curr_word.size();j++){
            auto it = upper_bound(mp[curr_word[j]].begin(), mp[curr_word[j]].end(),latest);
            if(it == mp[curr_word[j]].end()) break;
            latest = *it ;//*it for index of it. if we take it only then it will give the memory address.
            if(j == curr_word.size()-1) ans++;
        }
    }
    return ans;
    }
};
