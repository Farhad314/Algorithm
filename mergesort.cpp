#include<bits/stdc++.h>

using namespace std;

void mergesort(int A[],int p, int q);
void mergee(int A[],int p, int q, int r);

void printArray(int A[], int size)
{
    for (int i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main()
{
    cout<< "How many number will sort"<<endl;
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int arr_size = sizeof(arr)/sizeof(arr[0]);

    printf("Given array is \n");
    printArray(arr, arr_size);

    mergesort(arr, 0, arr_size - 1);

    printf("\nSorted array is \n");
    printArray(arr, arr_size);
    return 0;
}

 void mergee(int A[], int p, int q, int r) {
     int n1 = q - p + 1;
     int n2 = r - q;
     int i, j, k;
     int L[n1 + 1];
     int R[n2 + 1];

     L[n1] = 123456798;
     R[n2] = 123456798;

     for (i = 0; i < n1; i++)
         L[i] = A[p + i];
     for (j = 0; j < n2; j++)
         R[j] = A[q + j + 1];

     i = 0;
     j = 0;

     for (k = p; k <= r; k++) {
         if (L[i] <= R[j]) {
             A[k] = L[i];
             i++;
         } else {
             A[k] = R[j];
             j++;
         }
     }
 }

 void mergesort(int A[], int p, int r) {
     if(p < r) {
         int q = (p + r) / 2;
         mergesort(A, p, q);
         mergesort(A, q + 1, r);
         mergee(A, p, q, r);
     }
 }
