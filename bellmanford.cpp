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
#define INF 1e9
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int, pi> ppi;

vector<ppi> adj;
int d[501];
int n, m;

int main()
{
  scanf("%d %d", &n, &m);

  for (int i = 0; i < m; i++)
  {
    int a, b, d;
    scanf("%d %d %d", &a, &b, &d);

    adj.push_back(make_pair(a, make_pair(b, d)));
  }

  d[1] = 0;

  for (int i = 2; i <= n; i++)
    d[i] = INF;

  bool rlxf;

  for (int i = 0; i < n - 1; i++)
  {
    rlxf = false;
    for (int j = 0; j < m; j++)
    {
      //printf("%daa\n", adj[j].first);
      if (d[adj[j].first] != INF && d[adj[j].second.first] > d[adj[j].first] + adj[j].second.second)
      {
        d[adj[j].second.first] = d[adj[j].first] + adj[j].second.second;
        rlxf = true;
      }
    }
    if (!rlxf)
      break;
  }

  bool resf = false;

  if (rlxf)
    for (int j = 0; j < m; j++)
    {
      if (d[adj[j].second.first] > d[adj[j].first] + adj[j].second.second)
      {
        resf = true;
        break;
      }
    }

  if (resf)
    printf("-1\n");
  else
    for (int i = 2; i <= n; i++)
    {
      if (d[i] >= INF)
        printf("-1\n");
      else
        printf("%d\n", d[i]);
    }
  return 0;
}