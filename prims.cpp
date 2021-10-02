
#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back

const int N=1e5+5;

using ii=pair<int,int>;
// using iii=pair<int,pii >;

vector<ii>G[N];
int vis[N];
int cost;
int n,m;

void prims(int src)
{
  priority_queue<ii,vector<ii>,greater<ii> >pq;
  pq.push({0,src});
  while(!pq.empty())
  {
    ii tp=pq.top();
    pq.pop();
    if(vis[tp.se])
      continue;
    vis[tp.se]=1;
    cost+=tp.fi;

    for(auto it:G[tp.se])
    {
      if(!vis[it.fi])
        pq.push({it.se,it.fi});
    }
  }
  cout<<cost<<endl;
}


void solve()
{
  cin>>n>>m;
  cost=0;
  for(int i=0;i<=n;i++)
  {
    G[i].clear();
    vis[i]=0;
  }

  for(int i=0;i<m;i++)
  {
    int x,y,z;
    cin>>x>>y>>z;
    G[x].pb({y,z});
    G[y].pb({x,z});
  }
  prims(0);

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
