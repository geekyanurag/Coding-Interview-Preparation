// Problem is to find the union of two sorted arrays.
void findUnion(int arr1[], int arr2[], int n, int m)
{
    int x = max(arr1[n-1], arr2[m-1]);
    vector<int>res(x + 1, 0);
    for(int i =0; i<n; i++)
        if(res[arr1[i]] == 0)
            res[arr1[i]] = 1;
    for(int j =0; j<m; j++)
        if(res[arr2[j]] == 0)
            res[arr2[j]] = 1;
    for(int i = 0; i<res.size(); i++)
        if(res[i] == 1)
            cout<<i<<" ";
}