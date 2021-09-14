#include<bits/stdc++.h>
#include<vector>
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
using namespace std;

int CUT_ROD(vector<int> &,int,int []);
int MEMOIZED_CUT_ROD(vector<int> &p,int n)
{
    int r[n];
    for(int i=0;i<=n;i++)
        r[i]=-1000000;
    return CUT_ROD(p,n,r);
}

int CUT_ROD(vector<int> &p,int n,int r[])
{
    int q;
    if(r[n]>=0)
        return(r[n]);
    if(n==0)
        q= 0;
    else
        q=-1000000;

    for(int i=1;i<=n;i++)
        q=MAX(q,p[i]+CUT_ROD(p,n-i,r));
    r[n]=q;
    return r[n];

}

int main()
{
    int j,n;
    cout<<"Enter length of piece"<<endl;
    cin>>j;
    vector<int>p(j+1);
    cout<<"Enter price"<<endl;
    for(int i=1;i<=j;i++){
        cin>>p[i];
        }
    cout<<"Enter length of ROD: "<<endl;
    cin>>n;
    cout<<"Maximum revenue: "<<MEMOIZED_CUT_ROD(p,n)<<endl;
}
