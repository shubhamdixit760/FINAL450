#include<bits/stdc++.h>
#define int long long
using namespace std;
/*Comparing in pairs, if n is odd , initialise max, min with
  arr[0],else intialise max min by comparing first two elements
  then check in pairs , if the shorter of the two numbers is lesser than
  the currnt min then update current min, and same goes for max as well

  Time Complexity : T(n) = 3n/2 -2 
*/
pair<int,int> maxMinOfArray(int arr[],int n)
{
    pair<int,int>maxMin; //first denotes max and second ofpair denotes min
    //if n is odd
    int i;
    if(n%2)
    {
        maxMin.first = arr[0];
        maxMin.second = arr[0];
        //intialise i for further iterations
        i = 1;
    }
    else{
        if(arr[0]>arr[1]){
            maxMin.first = arr[0];
            maxMin.second = arr[1];
        }
        else{
            maxMin.first = arr[1];
            maxMin.second = arr[0];
        }
        //intialise i for further iterations
        i = 2;
    }

    while(i<n-1)
    {
        if(arr[i]>arr[i+1])
        {
            maxMin.first = max(maxMin.first,arr[i]);
            maxMin.second = min(maxMin.second,arr[i+1]);
        }
        else
        {
            maxMin.first = max(maxMin.first,arr[i+1]);
            maxMin.second = min(maxMin.second,arr[i]);
        }
        i += 2;
    }
    return maxMin;
}
int32_t main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin >> arr[i];
    
    pair<int,int>maxMin = maxMinOfArray(arr,n);
    cout <<  "Max element is : " << maxMin.first << endl;
    cout <<  "Min element is : " << maxMin.second << endl;
}