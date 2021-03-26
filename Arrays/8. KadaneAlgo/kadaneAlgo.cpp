// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.

    //every element looks behind, if the current sum is negative
    //it starts it own train further
    //else ,it just gets into the train of its ancestors
    //everytime the above process is done, the current sum is compared
    //with the overall best sum and updated if needed
    int maxSubarraySum(int arr[], int n){
        int currentBestSum = arr[0],overallBestSum = arr[0];
        int currentBestStart = 0,currentBestLength = 1;
        int overallBestStart = 0, overallBestLength = 1;
        for(int i=1;i<n;i++)
        {
            if(currentBestSum>=0){
                currentBestSum += arr[i],currentBestLength++;
            }else{
                currentBestSum = arr[i];
                currentBestStart = i, currentBestLength = 1;
            }
            if(currentBestSum>overallBestSum)
            {
                overallBestSum = currentBestSum;
                overallBestStart = currentBestStart;
                overallBestLength = currentBestLength;
            }
        }
        for(int i=overallBestStart;i<overallBestStart+overallBestLength;i++)
            cout << arr[i] << " ";
        cout << endl;
        return overallBestSum;
    }
};

// { Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}
  // } Driver Code Ends