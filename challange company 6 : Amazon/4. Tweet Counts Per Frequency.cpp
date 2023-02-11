class TweetCounts {
public:
    unordered_map<string, vector<int>> mp;
    TweetCounts() {
        mp.clear();
    }
    
    void recordTweet(string tweetName, int time) {
        mp[tweetName].push_back(time);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        int t = endTime-startTime;
        if(freq == "minute"){
            vector<int> ans(t/60+1,0);
            for(auto it: mp[tweetName]){
                if(it>=startTime && it<=endTime) ans[(it-startTime)/60]++;
            }
            return ans;
        }
        else if(freq == "hour"){
            vector<int> ans(t/3600+1,0);
            for(auto it: mp[tweetName]){
                if(it>=startTime && it<=endTime) ans[(it-startTime)/3660]++;
            }
            return ans;
        }
        else{
            vector<int> ans(t/(24*3600)+1,0);
            for(auto it: mp[tweetName]){
                if(it>=startTime && it<=endTime) ans[(it-startTime)/(24*3660)]++;
            }
            return ans;
        }
    //return {};
    }
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */
