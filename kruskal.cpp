int setnumber[1000001];

int find_set(int a)
{
  if (a == setnumber[a])
    return a;
  else
  {
    int p =find_set(setnumber[a]);
    setnumber[a] = p;
    return p;
  }
}

void set_union(int a, int b)
{
  int aparent = find_set(a);
  int bparent = find_set(b);
  
  if(aparent != bparent)
    setnumber[aparent] = bparent;
  return;
}

vector<pair<pi, int> > adj;

int kruskal(int v)
{
  int res = 0;
  
  for(int i = 1; i <= v; i++)
    setnumber[i] = i;
  
  sort(adj.begin(), adj.end(), [](pair<pi, int> a, pair<pi, int> b) -> bool {
      return a.second < b.second;
  });
  
  for(int i = 0; i < adj.size(); i++)
  {
    int vertex1 = adj[i].first.first;
    int vertex2 = adj[i].first.second;
    int weight = adj[i].second;
    
    if(find_set(vertex1) != find_set(vertex2))
    {
      set_union(vertex1, vertex2);
      res += weight;
    }
  }
  
  return res;
}