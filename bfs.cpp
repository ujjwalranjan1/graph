
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int inf=1e5+5;

int dist[N];
vector<int>G[N];
int n,m;

void bfs(int src)
{
  queue<int>q;
  dist[src]=0;
  q.push(src);
  while(!q.empty())
  {
    int u=q.front();
    q.pop();
    for(auto v:G[u])
    {
      if(dist[v]>dist[u]+1)
      {
        dist[v]=dist[u]+1;
        q.push(v);
      }
    }
  }
  for(int i=1;i<=n;i++)
    cout<<dist[i]<<" ";
  cout<<endl;
}

int main()
{
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("IN", "r", stdin);
  freopen("OUT", "w", stdout);
  #endif
  int t;
  cin>>t;
  while(t--)
  {
    cin>>n>>m;
    for(int i=0;i<=n;i++)
    {
      G[i].clear();
      dist[i]=inf;
    }
    for(int i=0;i<m;i++)
    {
      int x,y;
      cin>>x>>y;
      G[x].push_back(y);
      G[y].push_back(x);
    }
    bfs(1);
  }
  return 0;
}
