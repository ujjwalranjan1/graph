
#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second

using state=pair<int,int>;

const int N=1e5+5;
vector<char>G[N];
int dist[1005][1005];
const int inf=1e9;
int distx[]={1,1,1,0,-1,-1,-1,0};
int disty[]={1,0,-1,-1,-1,0,1,1};
int n,m;

bool check(state s)
{
  if(s.fi>=1 && s.fi<=n && s.se>=1 && s.se<=m && G[s.fi][s.se]!='#')
    return 1;
  return 0;
}

void bfs(state src)
{
  dist[src.fi][src.se]=0;
  queue<state>q;
  q.push(src);
  while(!q.empty())
  {
    state u=q.front();
    q.pop();
    for(int i=0;i<4;i++)
    {
      state v={u.fi+distx[i],u.se+disty[i]};
      if(check(v) && dist[v.fi][v.se]>dist[u.fi][u.se])
      {
        dist[v.fi][v.se]=dist[u.fi][u.se]+1;
        q.push(v);
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
  int t;
  cin>>t;
  while(t--)
  {
    cin>>n>>m;
    state src,des;
    for(int i=1;i<=n;i++)
    {
      G[i].resize(m+1);
      for(int j=1;j<=m;j++)
      {
        cin>>G[i][j];
        if(G[i][j]=='S')
          src={i,j};
        else if(G[i][j]=='E')
          des={i,j};
        dist[i][j]=inf;
      }
    }

    bfs(src);
    cout<<dist[des.fi][des.se]<<endl;
  }

  return 0;
}
