
#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
const int N=1e5+5;
vector<int>G[N];
bool vis[N];
vector<int>topo;
void dfs(int u)
{
  vis[u]=1;
  for(auto v:G[u])
    if(!vis[v])
      dfs(v);
  topo.push_back(u);
}


int main()
{
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("IN", "r", stdin);
  freopen("OUT", "w", stdout);
  #endif
  int n,m;
  cin>>n>>m;
  topo.clear();
  for(int i=0;i<=n;i++)
  {
    G[i].clear();
    vis[i]=0;
  }

  for(int i=0;i<m;i++)
  {
    int x,y;
    cin>>x>>y;
    G[x].push_back(y);
  }

  for(int i=1;i<=n;i++)
    if(!vis[i])
      dfs(i);

  reverse(topo.begin(),topo.end());
  for(auto it:topo)
    cout<<it<<" ";
  cout<<endl;


  return 0;
}
