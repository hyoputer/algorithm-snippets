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
#include <bits/stdc++.h>
#define INF 1e9
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<double, double> pd;
typedef pair<ll, ll> pl;

vector<int> adj[50001];
int depth[50001];
int parent[50001][16];

int lca(int a, int b)
{
    if (depth[a] < depth[b])
        swap(a, b);

    int dif = depth[a] - depth[b];

    int idx = 0;
    while (dif != 0)
    {
        if (dif % 2 == 1)
            a = parent[a][idx];

        dif /= 2;
        idx++;
    }

    while(a != b)
    {
        a = parent[a][0];
        b = parent[b][0];
    }

    return a;
}

void dfs(int cur, int pre)
{
    parent[cur][0] = pre;
    depth[cur] = depth[pre] + 1;

    for (int i = 0; i < adj[cur].size(); i++)
        if (adj[cur][i] != pre)
        {
            dfs(adj[cur][i], cur);
        }
}

int main()
{
    FILE *inF, *outF;
    inF = fopen("in", "r");
    outF = fopen("out", "w");
    //inF = stdin;
    //outF = stdout;

    int n;
    fscanf(inF, "%d", &n);

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        fscanf(inF, "%d %d", &a, &b);

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0);


    for (int i = 1;; i++)
    {
        bool f = false;

        for (int j = 1; j <= n; j++)
        {
            int next = parent[parent[j][i - 1]][i - 1];
            if (next != 0)
            {
                parent[j][i] = next;
                f = true;
            }
        }

        if (!f)
            break;
    }

    int m;
    fscanf(inF, "%d", &m);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        fscanf(inF, "%d %d", &a, &b);
        fprintf(outF, "%d\n", lca(a, b));
    }

        return 0;
}
//인풋 바꾸기!!!!