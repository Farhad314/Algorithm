#include<bits/stdc++.h>
using namespace std;


void lcs(char A[],char B[])
{
    int m = strlen(A);
    int n = strlen(B);
    char b[m][n];
    char LCS[m][n];
    for(int i=1;i<=m;i++)
    {
        LCS[i,0]= 'X';
    }
    for(int j=0;i<=n;j++)
    {
        LCS[0,j]= '0';
    }
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
    {
        if(A[i]==B[j])
        {
            LCS[i,j]=1+LCS[i-1,j-1];
            B[i,j]='Y';
        }
        else if(LCS[i-1,j]>=LCS[i,j-1])
        {
            LCS[i,j]=LCS[i-1,j];
            B[i,j]= 'U';
        }
        else
            LCS[i,j]=LCS[i,j-1];
            LCS[i,j] = 'B';
    }

    return LCS and B
}
