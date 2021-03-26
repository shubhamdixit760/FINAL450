#include<bits/stdc++.h>
#define int long long
using namespace std;
void printArray(int arr[],int n)
{
    for(int i=0;i<n;i++)
        cout << arr[i] << " ";
    cout << "\n";
}
void rearrange(int arr[],int n)
{
    int i = -1;
    for(int j=0;j<n;j++)
    {
        if(arr[j]<0)
        i++,swap(arr[i],arr[j]);
    }
}
void solve()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin >> arr[i];

    rearrange(arr,n);
    printArray(arr,n);
}
int32_t main()
{
    int t = 1;
    cin >> t;
    while(t--)
    solve();
}