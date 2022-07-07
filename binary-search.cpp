int f = 0;
int b = v.size();

while(f < b)
{
    int m = (b - f) / 2 + f;
    if (v[m] < num)
    {
        f = m + 1;
    }
    else
    {
        b = m;
    }
}

//f가 규칙에 맞는지 한번 더 테스트
//주로 f==v.size() 경우엔 안됨
