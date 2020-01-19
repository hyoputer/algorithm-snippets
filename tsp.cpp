#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <string.h>
#include <string>
#include <cmath>
#include <cstdio>
#include <functional>
#include <map>
#include <typeinfo>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

int w[16][16];
int dp[16][1 << 16];


int main()
{
  int n;
  scanf("%d", &n);
  
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      scanf("%d", &w[i][j]);
  
  for(int i = 0; i < n; i++)
    for(int j = 0; j < (1 << n); j++)
      dp[i][j] = INT_MAX;
  
  for(int i = 1; i < n; i++)
    if(w[0][i] != 0)
      dp[i][1<<i] = w[0][i];
  
  for(int i = 2; i < (1 << n); i++)
    for(int j = 1; j < n; j++)
    {
      if(dp[j][i] == INT_MAX)
        continue;

      for(int k = 1; k < n; k++)
      {
        if ((i & (1 << k)) || w[j][k] == 0) {
          continue;
        }

        dp[k][i | (1 << k)] = min(dp[k][i | (1 << k)], dp[j][i] + w[j][k]);
      }
    }
  
  for(int i = 1; i < n; i++)
    if(w[i][0] != 0 && dp[i][(1<<n)-2] != INT_MAX)
      dp[0][(1<<n)-1] = min(dp[0][(1<<n)-1], dp[i][(1<<n)-2] + w[i][0]);
  

  printf("%d\n",dp[0][(1<<n)-1]);
  
  return 0;
}
