int f = 0;
int b = v.size();

while(f < b)
{
    int m = (f + b) / 2;
    if (v[m] < num)
    {
        f = m + 1;
    }
    else
    {
        b = m;
    }
}