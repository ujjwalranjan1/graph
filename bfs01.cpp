
#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
using pii=pair<int,int>;

const int N=1e5+5;
const int inf=1e9;
int dist[10];
vector<pii>G[N];
int n,m;

void bfs01(int src)
{
  deque<int>q;
  dist[src]=0;
  q.push_back(src);
  while(!q.empty())
  {
    int u=q.front();
    q.pop_front();

    for(auto v:G[u])
    {
      if(dist[v.fi]>dist[u]+v.se)
      {
        dist[v.fi]=dist[u]+v.se;
        if(v.se)
          q.push_back(v.fi);
        else
          q.push_front(v.fi);
      }
    }
  }
}

int main()
{
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("IN", "r", stdin);
  freopen("OUT", "w", stdout);
  #endif
  cin>>n>>m;
  for(int i=0;i<=n;i++)
  {
    G[i].clear();
    dist[i]=inf;
  }
  for(int i=0;i<m;i++)
  {
    int x,y,w;
    cin>>x>>y>>w;
    G[x].push_back({y,w});
    G[y].push_back({x,w});
  }
  bfs01(1);
  for(int i=1;i<=n;i++)
    cout<<i<<" "<<dist[i]<<endl;
  return 0;
}
