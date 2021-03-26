// #include<bits/stdc++.h>
// using namespace std;
// pair<int,int>partition(vector<int>&arr,int l,int r)
//     {
//         int low = l,mid = l, high = r;
//         int pivot = arr[r];
//         while(mid<=high)
//         {
//             if(arr[mid]<pivot)
//             {
//                 swap(arr[mid],arr[low]);
//                 low++,mid++;
//             }
//             else if(arr[mid]==pivot)
//             {
//                 mid++;
//             }
//             else{
//                 swap(arr[mid],arr[high]);
//                 high--;
//             }
//         }
//         return {low-1,mid};
//     }
//     void quickSort(vector<int>&arr,int low,int high)
//     {
//         if(low<=high)
//         {
//             pair<int,int>p = partition(arr,low,high);
//             quickSort(arr,low,p.first);
//             quickSort(arr,p.second,high);
//         }
//     }
//     void sortArray(vector<int>& nums) {
//         quickSort(nums,0,nums.size()-1);
//     }

// int main()
// {
//     vector<int>arr;
//     int n;
//     cin >> n;
//     arr.resize(n);
//     for(int i=0;i<n;i++)
//         cin >> arr[i];

//     sortArray(arr);
//     for(auto x: arr)
//         cout << x << " ";
//     cout << "\n";
// }
#include <bits/stdc++.h>
using namespace std;
 
void rearrange(char arr[], int n)
{
    int i = -1;
    for (int j = 0; j < n; j++) {
        if (arr[j] == 'f') {
                i++,swap(arr[i], arr[j]);
        }
    }
}
 
// A utility function to print an array
void printArray(char arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%c ", arr[i]);
}
 
// Driver code
int main()
{
    char arr[] = { 'f','m','f','m','f','m','m','f'};
    int n = sizeof(arr) / sizeof(arr[0]);
    rearrange(arr, n);
    printArray(arr, n);
    return 0;
}