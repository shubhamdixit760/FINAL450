// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
       vector<pair<int,int>>v;
       vector<int>vis(n,0);
       for(int i=0;i<n;i++)
       {
           if(arr[i]-k >= 0)
            v.push_back({arr[i]-k,i});
            
            v.push_back({arr[i]+k,i});
       }    
       sort(v.begin(),v.end());
       int i=0,j=0,ele = 0;
       int ans = INT_MAX;
       while(j<v.size())
       {
           if(!vis[v[j].second])
            ele++;
           vis[v[j].second]++;
           
           if(ele == n){
            ans = min(ans,v[j].first-v[i].first);
               if(vis[v[i].second]==1)
                ele--;
                vis[v[i].second]--;
                i++;
        }
        if(ele<n)
           j++;
            
       }
       return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends