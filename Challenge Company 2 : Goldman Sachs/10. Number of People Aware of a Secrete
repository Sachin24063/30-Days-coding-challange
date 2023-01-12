class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
       int  modulo = 1e9+7;
       vector<int> person(2003,0);
       person[1] = 1;
       for(int i=1;i<=n;i++){
           for(int j=i+delay; j<i+forget; j++){
               person[j] = (person[j]+person[i]) % modulo;
           }
       }
       int secret = 0;
       for(int i=n-forget+1;i<=n;i++){
           secret = (secret + person[i])%modulo;
       }
   return secret;
    }
};
