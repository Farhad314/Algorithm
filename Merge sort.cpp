#include<bits/stdc++.h>
using namespace std;
void Merge(int *,int ,int ,int );
void merge_sort(int *A,int p,int q)
{
    int r;
    if(p<q)
    {
       r=(p+q)/2 ;
       merge_sort(A,p,r);
       merge_sort(A,r+1,q);

       Merge(A,p,r,q);
    }
}

void Merge(int *A,int p,int r,int q)
{
    int n1=r-p+1;
    int n2=q-r;
    int L[n1+1];
    int R[n2+1];

    int i,j;

    for(i=1;i<=n1;i++)
        L[i]=A[p+i-1];
    for(j=1;j<=n2;j++)
        R[j]=A[r+j];

    L[n1+1]=1000000;
    R[n2+1]=1000000;
    i=1;
    j=1;

    for(int k=p;k<=q;k++)
    {
        if(L[i]<=R[j])
           {
                A[k]=L[i];
                i=i+1;
           }
        else {

            A[k]=R[j];
            j=j+1;
        }
    }

}
int main()
{
    int A[30];
    int p=0,q;

    cout<<"Enter number of elements to be sorted:";
    cin>>q;
    cout<<"Enter "<<q<<" elements: ";
    for(int i=0;i<q;i++)
    {
        cin>>A[i];
    }
    merge_sort(A,p,q-1);
    cout<<"Sorted Array\n";
    for(int i=0;i<q;i++)
    {
        cout<<A[i]<<"\t";
    }
}
