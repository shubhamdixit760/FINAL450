// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:
/*
    Naive approach : 
    compare each element of array a with first element of array b
    if a[i] is greater than swap
    then the first element might not be at its correct position in array b
    so we use the logic of insertion sort to insert b[0] in the correct position
    in the sorted sublist b[1..m-1]
*/
	void merge(int a[], int b[], int n, int m) {
	    for(int i=0;i<n;i++)
	    {
	        if(a[i]>b[0])
	            swap(a[i],b[0]);
	           
	      int key = b[0];
	      int j;
	      for(j=1;j<m && key>b[j];j++)
	        b[j-1] = b[j];
	        
	      b[j-1] = key; 
	    }
	}
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, i;
        cin >> n >> m;
        int arr1[n], arr2[m];
        for (i = 0; i < n; i++) {
            cin >> arr1[i];
        }
        for (i = 0; i < m; i++) {
            cin >> arr2[i];
        }
        Solution ob;
        ob.merge(arr1, arr2, n, m);
        for (i = 0; i < n; i++) {
            cout << arr1[i] << " ";
        }
        for (i = 0; i < m; i++) {
            cout << arr2[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends