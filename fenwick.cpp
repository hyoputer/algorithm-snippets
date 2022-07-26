for (auto p : v)
    {
        int cur = p.second;

        int b = 0;
        while (cur > 0)
        {
            b += fenwick[cur];
            cur -= cur & (-cur);
        }
        res += s - b;

        cur = p.second;
        while (cur <= n)
        {
            fenwick[cur]++;
            cur += cur & (-cur);
        }
        s++;
    }
