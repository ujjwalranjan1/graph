
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second

const int N=1e5+5;
using state=pair<int,int>;

vector<string>g;

int dist1[1005][1005];
int dist2[1005][1005];
int dist3[1005][1005];

int x[]={1,0,-1,0};
int y[]={0,-1,0,1};
int n,m;

bool check(state s)
{
  return (s.fi>=0 && s.fi<n && s.se>=0 && s.se<m && g[s.fi][s.se]!='#');
}


void bfsmulti01(vector<state>&s,int dis[1005][1005])
{
  deque<state>dq;
  for(auto src:s)
  {
    dis[src.fi][src.se]=0;
    dq.push_back(src);
  }

  while(!dq.empty())
  {
    state u=dq.front();
    dq.pop_front();
    for(int i=0;i<4;i++)
    {
      state v={u.fi+x[i],u.se+y[i]};
      if(!check(v))
        continue;
      int cost=((g[v.fi][v.se]!=g[u.fi][u.se]) ||(g[v.fi][v.se]=='.'));
      if(dis[v.fi][v.se]>(dis[u.fi][u.se]+cost))
      {

        dis[v.fi][v.se]=dis[u.fi][u.se]+cost;
        if(cost==0)
          dq.push_front(v);
        else
          dq.push_front(v);
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
  g.resize(n);
  for(int i=0;i<n;i++)
    cin>>g[i];

  vector<state>v1,v2,v3;

  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
    {
      dist1[i][j]=dist2[i][j]=dist3[i][j]=1e9;
      if(g[i][j]=='1')
        v1.pb({i,j});
      else if(g[i][j]=='2')
        v2.pb({i,j});
      else if(g[i][j]=='3')
        v3.pb({i,j});
    }

  bfsmulti01(v1,dist1);
  bfsmulti01(v2,dist2);
  bfsmulti01(v3,dist3);
  return 0;
}
