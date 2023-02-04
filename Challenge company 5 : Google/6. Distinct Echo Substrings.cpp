#define ll long long
class Solution {
public:
    int distinctEchoSubstrings(string text) {
        ll m = 1e9;
        int p =31;
        int n = text.size();
        vector<ll> p_n(n);
        p_n[0] = 1;
        for(int i=1;i<n; i++){
            p_n[i] = (p_n[i-1]*p)%m;
        }
        vector<ll> hash(n+1,0);
        for(int i=0;i<n;i++){
            hash[i+1] = (hash[i]+(text[i]-'a'+1) * p_n[i])%m;
        }
        unordered_map<ll, ll> mp;
        for(int i=2;i<=n;i+=2){
            for(int j=0;j+i<=n;j++){
               ll curr1= (hash[j+i/2]+m-hash[j])%m;
                curr1=(curr1*p_n[n-j-1])%m; 
                ll curr2= (hash[j+ i] +m - hash[j+i/2])%m; 
                curr2=(curr2*p_n[n-j-1-i/2])%m;
                if(curr1==curr2)
                {
                    mp[curr1]++;
                }
            }
        }
        return mp.size();
    }
};
