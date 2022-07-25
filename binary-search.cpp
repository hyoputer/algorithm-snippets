int f = 0;
int b = v.size();

while(f < b)
{
    int m = (b - f) / 2 + f; //mid 오버플로우 방지 and f+b가 음수 가능성 있을 때 버그 방지
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
