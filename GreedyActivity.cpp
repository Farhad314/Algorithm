#include<bits/stdc++.h>

using namespace std;

void greedy_Activity_Selector(int s[], int f[], int n)
{
    int i, j;

    printf ("Following activities are selected \n");
    i = 0;
    printf("%d ", i);
    for (j = 1; j < n; j++)
    {

        if (s[j] >= f[i])
        {
            printf ("%d ", j);
            i = j;
        }
    }
}

int main()
{
    int s[] =  {1, 2, 4, 1, 5, 8,9,11,13};
    int f[] =  {3, 5, 7, 8, 9, 10,11,14,16};
    int n = sizeof(s)/sizeof(s[0]);
    greedy_Activity_Selector(s, f, n);
    return 0;
}
