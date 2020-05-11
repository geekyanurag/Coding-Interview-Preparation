// Problem is to find the intersection of two sorted arrays.
void printIntersection(int arr1[], int arr2[], int N, int M) 
{ 
    unordered_map<int,int>mp;
    for(int i=0; i<N; i++){
        mp[arr1[i]]++;
    }
    set<int>s;
    for(int i = 0; i<M; i++){
        if(mp[arr2[i]])
            s.insert(arr2[i]);
    }
    if(s.size() == 0)
        cout<<"-1";
    else{
    for(auto i : s)
        cout<<i<<" ";
    }
}