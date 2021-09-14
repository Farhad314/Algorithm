#include<bits/stdc++.h>
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
using namespace std;
int CUT_ROD(int p[],int n)
{
    int q;
    if(n==0){
        return 0;
    }

        q=-1000000;

    for(int i=1;i<=n;i++){
        cout<<"i="<<i<<" n="<<n<<" p["<<i<<"]="<<p[i]<<" q="<<q<<endl;
        q=MAX(q,p[i]+CUT_ROD(p,n-i));
        cout<<"\t q= "<<q<<endl;
    }

    return q;
}
int main() {
  // array starting from 1, element at index 0 is fake
  int p[] = {0, 1, 5, 8, 9, 10};
  cout<<CUT_ROD(p,5)<<endl;
  return 0;
}
