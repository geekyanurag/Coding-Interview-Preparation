#include<bits/stdc++.h>
using namespace std;

// Problem is to find the number of pairs such that it satisfies x to the power y > y to power x where x is an element from first array and y is element from second array
// Solution is there are some exceptions for x which is written in count for which the above condition doesn't satisfies.
int count(int x, vector<int>y, int num[]){
    if(x == 0) return 0;

    if(x == 1) return num[0];

    int n = y.size();
    auto z = upper_bound(y.begin(), y.end(), x);  // Finding the element which is just greater than the value x.
    int count = (y.begin() + n) - z;  // And taking all the elements which are greater than x as a count ie. count of all the elements which is greater than x in second array.

    count += num[0] + num[1];
    if(x == 2) count -= (num[3] + num[4]);  // if x is 2 then all the number of 3's and 4's from second array will not contribute to the counting pairs.

    if(x == 3) count += num[2];  // if x is 3 then count of 2's in second array will contribute to count.

    return count;
}

int solve(vector<int>x, vector<int>y){
    int n = x.size(), m = y.size();
    int num[5] = {0};  // Store the count of number of 0 , 1, 2, 3, 4 in y.
    for(int i = 0; i<m; i++){
        if(y[i] < 5)
            num[y[i]]++;
    }
    sort(y.begin(), y.end());  // So that we can binary search the element just greater than x
    int total = 0;
    for(int i = 0; i<n; i++)
        total += count(x[i], y, num);
    return total;
}

int main(){
    int n, m;
    cin>>n>>m;
    vector<int>x(n), y(m);
    for(int i = 0; i<n; i++)
        cin>>x[i];
    for(int i = 0; i<m; i++)
        cin>>y[i];
    int res = solve(x, y);
    cout<<res<<endl;
    return 0;
}