// Problem is to check if a string is a balanced parenthesis or not. e.g = s = {([])} is a balanced parenthesis string.
bool ispar(string x)
{
    bool res;
    stack<char>s;
    s.push(x[0]);
    for(int i =1; i<x.length(); i++){
        if(x[i] == '{' || x[i] == '(' || x[i] == '[')
            s.push(x[i]);
        else{
                if(!s.empty()){
                if(s.top() == '(' && x[i] == ')')
                    s.pop();
                else if(s.top() == '[' && x[i] == ']')
                    s.pop();
                else if(s.top() == '{' && x[i] == '}')
                    s.pop();
                else {
                    res = false;
                    break;
                }
                }
        }
    }
    if(s.empty())
        res = true;
    else
        res = false;
    return res;
}