vector<pi> adj[100001];
int visited[100001];

pi traverse(int n)
{
  //printf("%daa\n", n);
  visited[n] = 1;
  vector<int> childs;
  int diameter = 0;
  for(int i = 0; i < adj[n].size(); i++)
  {
    if(visited[adj[n][i].first] == 0)
    {
      pi next = traverse(adj[n][i].first);
      childs.push_back(adj[n][i].second + next.first);
      diameter = max(diameter, next.second);
    }
  }
  
  sort(childs.begin(), childs.end(), greater<int>());
  
  if (childs.size() >= 2)
    diameter = max(diameter, childs[0] + childs[1]);
  else if (childs.size() == 1)
    diameter = max(diameter, childs[0]);
  
  if (childs.empty())
    return make_pair(0, diameter);
  else
    return make_pair(childs[0], diameter);
}

pi adj[100001];
string preorder;
string inorder;
string postorder;

void traverse(char c)
{
  //printf("%daa\n", n);
  preorder += c;
  //printf("%saa\n", res.c_str());
  
  if(adj[c].first != '.')
    traverse(adj[c].first);
  
  inorder += c;
  
  if(adj[c].second != '.')
    traverse(adj[c].second);
  
  postorder += c;
  
  return ;
}