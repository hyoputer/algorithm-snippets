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
    inF = fopen("in", "r");
    outF = fopen("out", "w");
    //inF = stdin;
    //outF = stdout;

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