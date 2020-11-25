// idx: 1 ~ n
ll arr[1000001];
ll tree[3000000];
int n;

ll makeSegmentTree(int node, int start, int end)
{
    if (start == end)
        tree[node] = arr[start];
    else
        tree[node] = makeSegmentTree(node * 2, start, (start + end) / 2) + makeSegmentTree(node * 2 + 1, (start + end) / 2 + 1, end);

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

    for (int n : nodes)
        tree[n] = tree[n] - tree[node] + num;
}

ll getSum(int start, int end, int segStart, int segEnd, int node)
{
    if (start == segStart && end == segEnd)
        return tree[node];

    int mid = (segStart + segEnd) / 2;

    if (start <= mid && end > mid)
        return getSum(start, mid, segStart, mid, node * 2) + getSum(mid + 1, end, mid + 1, segEnd, node * 2 + 1);

    if (end <= mid)
        return getSum(start, end, segStart, mid, node * 2);

    if (start > mid)
        return getSum(start, end, mid + 1, segEnd, node * 2 + 1);
}