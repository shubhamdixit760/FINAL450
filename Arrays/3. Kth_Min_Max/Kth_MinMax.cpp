// { Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

int kthSmallest(int *, int, int, int);
 
int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        cout<<kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}// } Driver Code Ends

//partition procedure to set pivot(last element of given subarray) at its 
//correct position
int partition(int arr[],int l,int r)
{
    int pivot = arr[r];
    int potential_pivot = l-1;
    for(int j=l;j<r;j++)
    {
        if(arr[j]<pivot)
            potential_pivot++, swap(arr[potential_pivot],arr[j]);
    }
    
    potential_pivot++;
    swap(arr[r],arr[potential_pivot]);
    return potential_pivot;
}

int randPartition(int arr[],int l, int r)
{
    int x = rand()%(r-l+1) + l;
    swap(arr[r],arr[x]);
    return partition(arr,l,r);
}
//User function template for C++

// arr : given array
// l : starting index of the array i.e 0
// r : ending index of the array i.e size-1
// k : find kth smallest element and return using this function
int kthSmallest(int arr[], int l, int r, int k) {
   int q = randPartition(arr,l,r);
   int i = q - l + 1;//relative rank of pivot
   if(i==k)
    return arr[q];
    
   else if(i>k)
    return kthSmallest(arr,l,q-1,k);
    
   else
    return kthSmallest(arr,q+1,r,k-i);
}