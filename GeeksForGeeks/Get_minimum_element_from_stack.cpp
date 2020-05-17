/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

/*returns min element from stack*/
int _stack :: getMin()
{
    if(s.empty())
        return -1;
    else {
   stack<int>st = s;
   minEle = st.top();
   while(!st.empty()){
       minEle = min(minEle, st.top());
       st.pop();
   }
   return minEle;
    }
}

/*returns poped element from stack*/
int _stack ::pop()
{
    if(s.empty())
        return -1;
    else {
   int x = s.top();
   s.pop();
   return x;
    }
}

/*push element x into the stack*/
void _stack::push(int x)
{
    s.push(x);
}