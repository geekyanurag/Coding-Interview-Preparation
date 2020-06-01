#include<bits/stdc++.h>
using namespace std;

// Given a column number then find the column name e.g = n = 51 , string s will be AY.
// Method - 1
string colname(int n){
    string s;

    while(n > 0){
        int r = n % 26;
        if(r == 0){
            s += 'Z';
            n = (n / 26) - 1;
        }
        else{
            s += (r - 1) + 'A';
            n = n / 26;
        }
    }
    reverse(s.begin(), s.end());
    return s;
}

// Method - 2
void printString(int n){
    int arr[10000];
    int i = 0;
    while(n){
        arr[i] = n % 26;
        n /= 26;
        i++;
    }

    for(int j = 0; j<i-1; j++){
        if(arr[j] <= 0){
            arr[j] += 26;
            arr[j+1] = arr[j+1] - 1;
        }
    }

    for(int j = i; j>=0; j--){
        if(arr[j] > 0){
            cout<<char('A' + arr[j] - 1);
        }
    }
    cout<<endl;
}

int main(){
    int n;
    cin>>n;
    string st = colname(n);
    cout<<st<<endl;
    printString(n);
    return 0;
}