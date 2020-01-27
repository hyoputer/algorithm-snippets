int setnumber[200001];
int setsize[200001];

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
  {
    //printf("%daaa\n", aparent);
    setnumber[aparent] = bparent;
    setsize[bparent] += setsize[aparent];
  }
  return;
}