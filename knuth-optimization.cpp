for int i = 0; i < n; i++)
{
    dp[i][i] = 0;
    p[i][i] = i;
}

for (int i = 1; i < n; i++)
{
    for (int j = 0; i + j < n ; j++)
    {
        s = i, e = i + j - 1;
        dp[s][e] = vMax;

        for (int k = p[s][e - 1]; k <= p[s + 1][e]; k++)
        {
            if (dp[s][e] > dp[s][k] + dp[k + 1][e])
            {
                dp[s][e] = dp[s][k] + dp[k + 1][e];
                p[s][e] = k;
            }
        }

        dp[s][e] += cost[s][e];
    }
}