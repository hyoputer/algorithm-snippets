
vector<int> adj[100001];

pi traverse(int cur, int pre)
{
  //printf("%daa\n", n);
  vector<int> childs;
  int diameter = 0;
  for (int i = 0; i < adj[cur].size(); i++)
  {
    if (adj[cur][i] != pre)
    {
      pi next = traverse(adj[cur][i], cur);
      childs.push_back(next.first + 1);
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