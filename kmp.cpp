
char t[1000001];
char p[1000001];

int ch[1000001];

fscanf(inF, "%[^\n]s", t);
getc(inF);
fscanf(inF, "%[^\n]s", p);

int plen = strlen(p);

ch[0] = 0;
ch[1] = 0;
int idx = 0;
for (int i = 1; i < plen; i++)
{
    if (p[i] == p[idx])
    {
        ch[i + 1] = idx + 1;
        idx++;
    }
    else if (idx != 0)
    {
        i--;
        idx = ch[idx];
    }
    else
    {
        ch[i + 1] = 0;
    }
}

int tlen = strlen(t);
int res = 0;
vector<int> residx;
idx = 0;

for (int i = 0; i < tlen; i++)
{
    if (t[i] == p[idx])
    {
        idx++;
        if (idx == plen)
        {
            residx.push_back(i - plen + 2);
            res++;
            idx = ch[idx];
        }
    }
    else if (idx != 0)
    {
        i--;
        idx = ch[idx];
    }
}