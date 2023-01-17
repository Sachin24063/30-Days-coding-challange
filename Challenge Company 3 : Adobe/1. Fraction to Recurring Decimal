class Solution {
public:
    string fractionToDecimal(long long numerator,long long  denominator) {
        if (numerator == 0) return "0";
        string ans;
        if((numerator<0 && denominator>0) || (numerator>0 && denominator<0)){
            ans.push_back('-');
        }
        numerator = abs(numerator);
        denominator = abs(denominator);

        ans+= to_string(numerator/denominator);
        if(numerator % denominator == 0){return ans;}

        ans+='.';

        unordered_map<int , int> mp;
        for(long long i=numerator % denominator; i; i%=denominator){
            if(mp.count(i)>0){
                ans.insert(mp[i],1,'(');
                ans+=')';
                break;
            }
            mp[i] = ans.size();
            i*=10;
            ans += to_string(i/denominator);
        }

    return ans;
    }
};
