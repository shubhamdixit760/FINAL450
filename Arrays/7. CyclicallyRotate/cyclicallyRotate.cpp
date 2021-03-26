// { Driver Code Starts
#include <stdio.h>

void rotate(int arr[], int n);

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int a[n] , i;
        for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        rotate(a, n);
        for (i = 0; i < n; i++)
            printf("%d ", a[i]);
        printf("\n");
    }
        return 0;
}
// } Driver Code Ends

void swap(int *x,int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void rotate(int arr[], int n)
{
    for(int i=n-2;i>=0;i--)
    {
        swap(&arr[i],&arr[i+1]);
    }
}