int dist[401][401];
int pre[401][401];

void floyd_warshall(int n)
{
  
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++)
      for(int k = 1; k <= n; k++)
      {
              //printf("%d %d %d\n", j, k, dist[j][k]);

        if(dist[j][k] > dist[j][i] + dist[i][k])
        {
          dist[j][k] = dist[j][i] + dist[i][k];
          pre[j][k] = i;
        }
      }
}

int main()
{
  int n, m;
  scanf("%d %d", &n, &m);
  
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++)
      dist[i][j] = 1e9;
  
  while(m--)
  {
    int a, b, d;
    scanf("%d %d %d", &a, &b, &d);
    
    dist[a][b] = min(dist[a][b], d);
    
    pre[a][b] = a;
  }
  
  floyd_warshall(n);
  
  return 0;
}