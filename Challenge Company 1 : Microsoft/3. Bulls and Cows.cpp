class Solution {
public:
    string getHint(string secret, string guess) {
       vector<int>key(10,0);
       vector<int>g(10,0);
       int bulls = 0;
       for(int i=0;i<secret.size();i++){
           if(secret[i]==guess[i]){
               bulls++;
           }
           else{
               key[secret[i]-'0']= key[secret[i]-'0']+1;
               g[guess[i]-'0']= g[guess[i]-'0']+1;
           }
       } 
       int cow=0;
       for(int i=0;i<10;i++){
           cow+= min(key[i],g[i]);
       }
    string ans = "";
    ans+=to_string(bulls);
    ans+='A';
    ans+=to_string(cow);
    ans+='B';
    return ans;
    }
};
