class Solution {
public:
    int numberOfSubstrings(string s) {
        int a_i=-1,b_i=-1,c_i=-1,count=0;
        for (int i=0;i<s.length();i++){
            if (s[i]=='a'){
                a_i = i;
            }
            if(s[i]=='b'){
                b_i=i;
            }
            if(s[i]=='c'){
                c_i=i;
            }
            int temp = min(a_i,b_i);
    count+= min(temp,c_i)+1;
    }
    return count;
    }
};
