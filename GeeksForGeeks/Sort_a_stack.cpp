// Problem is to sort a stack.
void SortedStack :: sort()
{
    int n = s.size();
    vector<int>v(n);
    int k = 0;
   while(!s.empty()){
       v[k++] = s.top();
       s.pop();
   }
   for(int i =0; i<n; i++){
       for(int j = 0; j<n - i - 1; j++){
           if(v[j] > v[j+1]){
               int temp = v[j];
               v[j] = v[j+1];
               v[j+1] = temp;
           }
       }
   }
   
   for(int i : v){
       s.push(i);
   }
}