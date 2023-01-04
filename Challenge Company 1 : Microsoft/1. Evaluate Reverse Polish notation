//Language : C++

class Solution{
    public:
    int evalRPN(vector<string>& tokens){
        stack<int> s;
        for(string s1: tokens){
            if(s1 == "+"){
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(a+b);
            }
            else if(s1 == "-"){
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(b-a);
            }
            else if(s1 == "*"){
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(a*b);
            }
            else if(s1 == "/"){
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(b/a);
            }
            else{
                s.push(stoi(s1));
            }
        }
    return s.top();
    }
};
