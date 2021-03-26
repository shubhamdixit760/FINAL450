// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	void merge(int a[], int b[], int n, int m) {
	    int gap = ceil((m+n)/2.0);
	    while(1)
	    {
	        int i = 0,j = i + gap;
	        while(j<(m+n))
	        {
	            if(i<n && j<n)//both the elements are in first array
	            {
	                if(a[i]>a[j])
	                swap(a[i],a[j]);
	            }
	            else if(i<n && j>=n)//one element is in a and other is in b
	           {
	               if(a[i]>b[j-n])
	                swap(a[i],b[j-n]);
	           }
	           else{//both the elemens are in b
	               if(b[i-n]>b[j-n])
	                swap(b[i-n],b[j-n]);
	           }
	           i++,j++;
	        }
	        if(gap==1)return ;
	        gap = ceil(gap/2.0);
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