#include<bits/stdc++.h>

void knapSack(int W, int n, int val[], int wt[]);
int getMax(int x, int y);

int main() {


  int val[] = {-1, 100, 41, 120, 40};
  int wt[] = {-1, 3, 2, 5, 1};

  int n = 4;
  int W = 5;

  knapSack(W, n, val, wt);

  return 0;
}

int getMax(int x, int y) {
  if(x > y) {
    return x;
  } else {
    return y;
  }
}

void knapSack(int W, int n, int val[], int wt[]) {
  int i, w;

  int V[n+1][W+1];

  for(w = 0; w <= W; w++) {
    V[0][w] = 0;
  }

  for(i = 0; i <= n; i++) {
    V[i][0] = 0;
  }

  for(i = 1; i <= n; i++) {
    for(w = 1; w <= W; w++) {
      if(wt[i] <= w) {
        V[i][w] = getMax(V[i-1][w], val[i] + V[i-1][w - wt[i]]);
      } else {
        V[i][w] = V[i-1][w];
      }
    }
  }

  printf("Max Value: %d\n", V[n][W]);
}
