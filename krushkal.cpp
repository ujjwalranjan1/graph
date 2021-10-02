
#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
const int N=1e5+5;

vector<pair<int,pair<int,int> > >edges;
int n,m;
vector<int>par;
vector<int>sz;


int find(int v)
{
  if(v!=par[v]) return par[v]=find(par[v]);
    return v;
}

void unionx(int u,int v,int& cost,int price)
{
  u=find(u);
  v=find(v);
  if(u==v)
    return ;

  if(sz[u]>sz[v])
    swap(u,v);

  par[u]=v;
  sz[v]+=sz[u];
  cost+=price;
}

void solve()
{
  cin>>n>>m;
  edges.clear();
  par.resize(n+1);
  sz.resize(n+1);

  for(int i=0;i<=n;i++)
    par[i]=i,sz[i]=1;


  for(int i=0;i<m;i++)
  {
    int x,y,z;
    cin>>x>>y>>z;
    edges.push_back({z,{x,y}});
  }
  sort(edges.begin(),edges.end());
  int cost=0;

  for(int i=0;i<m;i++)
  {
    int price=edges[i].first;
    int u=edges[i].second.first;
    int v=edges[i].second.second;
    unionx(u,v,cost,price);
  }
  cout<<cost<<endl;
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
    solve();
  }
  return 0;
}
