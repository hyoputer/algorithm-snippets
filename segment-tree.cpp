ll makeSegmentTree(int node, int start, int end)
{
    if (start == end)
        tree[node] = arr[start];
    else
        tree[node] = makeSegmentTree(node * 2, start, (start + end) / 2) * makeSegmentTree(node * 2 + 1, (start + end) / 2 + 1, end) % MOD;

    return tree[node];
}

void changeNumber(int idx, ll num)
{
    int start = 1;
    int end = n;
    int node = 1;
    vector<int> nodes;
    nodes.push_back(node);

    while (start != end)
    {
        if (idx <= (start + end) / 2)
        {
            node = node * 2;
            end = (start + end) / 2;
        }
        else
        {
            node = node * 2 + 1;
            start = (start + end) / 2 + 1;
        }
        nodes.push_back(node);
    }

    tree[node] = num;

    for (int i = (int)nodes.size() - 2; i >= 0; i--)
        tree[nodes[i]] = tree[nodes[i] * 2] * tree[nodes[i] * 2 + 1] % MOD;
}

ll getMult(int start, int end, int segStart, int segEnd, int node)
{
    if (start == segStart && end == segEnd)
        return tree[node];

    int mid = (segStart + segEnd) / 2;

    if (start <= mid && end > mid)
        return getMult(start, mid, segStart, mid, node * 2) * getMult(mid + 1, end, mid + 1, segEnd, node * 2 + 1) % MOD;

    if (end <= mid)
        return getMult(start, end, segStart, mid, node * 2);

    if (start > mid)
        return getMult(start, end, mid + 1, segEnd, node * 2 + 1);
}