#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

int max(int a, int b) { return (a > b)? a : b; }

int max(int a, int b, int c) { return max(max(a, b), c); }

int max_crossing_subarray(int *A,int low,int mid,int high)
{
    int left_sum=-123;
    int sum=0,max_left,max_right;
    for(int i=mid;i>=low;i--)
    {
        sum=sum+A[i];
        if(sum>left_sum)
        {
            left_sum=sum;
            max_left=i;
        }
    }
    int right_sum=-123;
    sum=0;
    for(int j=mid+1;j<=high;j++)
    {
            sum = sum+A[j];
            if(sum>right_sum)
            {
                right_sum=sum;
                max_right=j;
            }
    }
    return (max_left,max_right,left_sum+right_sum);
}
int maximum_subarray(int *A,int low,int high)
{
    int mid;
    if(high==low)
        return(low,high,A[low]);
    else mid = (low+high)/2;

    return max(maximum_subarray(A, low, mid),
              maximum_subarray(A, mid+1, high),
              max_crossing_subarray(A, low, mid, high));

}
int main()
{
   int arr[] = {-2, 3, -4, 5,8,5, 7};
   int n = sizeof(arr)/sizeof(arr[0]);
   int max_sum = maximum_subarray(arr, 0, n-1);
   cout<<max_sum;

   return 0;
}
