#include<bits/stdc++.h>
using namespace std;

struct Interval{
    int start, end;
};

bool compare(Interval a, Interval b){
    return a.start < b.start;
}

// Method - 1 using stack
// Time - O(nlogn) , space - O(n)
void solve(Interval arr[], int n){
    if(n <= 0)
        return; 
    sort(arr, arr + n, compare);
    stack<Interval>st;
    st.push(arr[0]);

    for(int i =1; i<n; i++){
        Interval top = st.top();
        if(top.end < arr[i].start)
            st.push(arr[i]);
        else if(top.end < arr[i].end){
            top.end = arr[i].end;
            st.pop();
            st.push(top);
        }
    }

    // Printing the merged intervals
    while(!st.empty()){
        Interval top = st.top();
        cout<<top.start<<" "<<top.end<<endl;
        st.pop();
    }

}

// Method - 2 Without using stack
// Time - O(nlogn) , Space - O(1)
void solve2(Interval arr[], int n){
    sort(arr, arr + n, compare);
    int index = 0;
    for(int i = 1; i<n; i++){
        if(arr[index].end >= arr[i].start){
            arr[index].end = max(arr[index].end, arr[i].end);
            arr[index].start = min(arr[index].start, arr[i].start);
        }
        else{
            arr[index] = arr[i];
            index++;
        }
    }
    // Printing the output intervals
    for(int i =0; i<=index; i++){
        cout<<arr[i].start<<" "<<arr[i].end<<endl;
    }
}

int main(){
    int n;
    cin>>n;
    Interval arr[n];
    for(int i = 0; i<n; i++)
        cin>>arr[i].start>>arr[i].end;
    //solve(arr, n);
    solve2(arr, n);
    return 0;
}