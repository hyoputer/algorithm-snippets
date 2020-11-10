vector<int> nextv[32001];
int pre[32001];
vector<int> sorted;
int n;

bool topsort()
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

    if (sorted.size() != n)
        return false;
    else
        return true;
}

int main()
{
    FILE *inF, *outF;
    inF = stdin;
    outF = stdout;

    int m;
    fscanf(inF, "%d %d", &n, &m);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        fscanf(inF, "%d %d", &a, &b);

        nextv[a].push_back(b);
        pre[b]++;
    }

    topsort();

    for (int i = 0; i < sorted.size(); i++)
        fprintf(outF, "%d ", sorted[i]);

    return 0;
}
//인풋 바꾸기!!!!