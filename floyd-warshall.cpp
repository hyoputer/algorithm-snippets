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
#define INT_MAX 2147483647
#define INT_MIN -2147483647
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

int dist[101][101];
int pre[101][101];

int main()
{
  int n, m;
  scanf("%d %d", &n, &m);
  
  while(m--)
  {
    int a, b, d;
    scanf("%d %d %d", &a, &b, &d);
    
    if (dist[a][b] != 0)
      dist[a][b] = min(dist[a][b], d);
    else
      dist[a][b] = d;
    
    pre[a][b] = a;
  }
  
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++)
    {
      if (dist[j][i] != 0)
      {
        for(int k = 1; k <= n; k++)
        {
          
          if (dist[i][k] != 0)
          {
            //printf("%d %d %d\n", j, k, dist[j][k]);
            if (dist[j][k] != 0)
            {
              if(dist[j][k] > dist[j][i] + dist[i][k])
              {
                dist[j][k] = dist[j][i] + dist[i][k];
                pre[j][k] = i;
              }
            }
            else
            {
                dist[j][k] = dist[j][i] + dist[i][k];
                pre[j][k] = i;
            }
          }
        }
      }
    }
  
  for(int i = 1; i <= n; i++)
  {
    for(int j = 1; j <= n; j++)
      printf("%d ", dist[i][j]);
    
    printf("\n");
  }
  
  return 0;
}
