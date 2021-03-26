#include<bits/stdc++.h>
#define int long long
using namespace std;
/*Divide and conquer approach (Tournament method), if array has only one element, return that
  max and min, if it has two then one comparison is required to return the pair
  else recur for left and right subarrays and when there maxMin pairs are returned
  compare their max and min respectively to get the ultimate winner

  Time complexity : T(n) = 2*T(n/2) + 2 => T(n) = 3n/2 - 2
*/
pair<int,int> maxMinOfArray(int arr[],int l,int r)
{
   //creating pairs for maxMin of left and right subarrays
   pair<int,int> maxMinLeft,maxMinRight;

   //if array has only one element
   if(l==r)
        return {arr[l],arr[r]};

    else if(r==l+1) //i.e array has two elements
    {
        if(arr[l]>arr[r])
            return {arr[l],arr[r]};
        else 
            return {arr[r],arr[l]};
    }

    // recursively call for left and right subarrays
    int mid = (l+r)/2;
    maxMinLeft = maxMinOfArray(arr,l,mid);
    maxMinRight = maxMinOfArray(arr,mid+1,r);

    //finding absolute winner from the two halves
    int absoluteMax,absoluteMin;
    absoluteMax = max(maxMinLeft.first,maxMinRight.first);
    absoluteMin = min(maxMinLeft.second,maxMinRight.second);

    return {absoluteMax,absoluteMin};
}
int32_t main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin >> arr[i];
    
    pair<int,int>maxMin = maxMinOfArray(arr,0,n-1);
    cout <<  "Max element is : " << maxMin.first << endl;
    cout <<  "Min element is : " << maxMin.second << endl;
}