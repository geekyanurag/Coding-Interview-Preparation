#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    vector<int> sum(nums.size(), 0);
    unordered_map<int, int> mp;
    int max_sum = 0;
    sum[0] = (nums[0] == 0 ? -1 : 1);
    for (int i = 1; i < nums.size(); i++)
    {
        sum[i] = sum[i - 1] + (nums[i] == 0 ? -1 : 1);
    }
    for (int i = 0; i < sum.size(); i++)
    {
        if (mp.find(sum[i]) == mp.end())
        {
            mp[sum[i]] = i;
        }
    }
    for (int i = 0; i < sum.size(); i++)
    {
        int x = i - mp[sum[i]];
        max_sum = (x > max_sum) ? x : max_sum;
    }
    cout<<max_sum;
}