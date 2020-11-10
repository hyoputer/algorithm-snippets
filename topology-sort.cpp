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

vector<int> nextv[501];
int pre[501];
vector<int> sorted;
int n;

void topsort()
{
    queue<int> q;

    for (int i = 1; i <= n; i++)
    {
        if (pre[i] == 0)
        {
            q.push(i);
            sorted.push_back(i);
        }
    }

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < nextv[cur].size(); i++)
        {
            pre[nextv[cur][i]]--;
            if (pre[nextv[cur][i]] == 0)
            {
                q.push(nextv[cur][i]);
                sorted.push_back(nextv[cur][i]);
            }
        }
    }
}

int main()
{
    FILE *inF, *outF;
    inF = stdin;
    outF = stdout;

    fscanf(inF, "%d", &n);

    vector<int> prev[501] = {};
    int time[501] = {};

    for (int i = 1; i <= n; i++)
    {
        int num;
        fscanf(inF, "%d", &num);
        while (num != -1)
        {
            if (time[i] == 0)
            {
                time[i] = num;
            }
            else
            {
                prev[i].push_back(num);
                nextv[num].push_back(i);
                pre[i]++;
            }

            fscanf(inF, "%d", &num);
        }
    }

    topsort();

    int dp[501] = {};

    for (int i = 0; i < sorted.size(); i++)
    {
        int curtime = 0;
        for (int j = 0; j < prev[sorted[i]].size(); j++)
        {
            curtime = max(dp[prev[sorted[i]][j]], curtime);
        }

        dp[sorted[i]] = curtime + time[sorted[i]];
    }

    for (int i = 1; i <= n; i++)
    {
        fprintf(outF, "%d\n", dp[i]);
    }

    return 0;
}
//인풋 바꾸기!!!!