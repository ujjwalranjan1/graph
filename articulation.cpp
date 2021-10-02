
#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
const int N=1e5+5;
const int inf=1e9;
vector<int>G[N];
int intime[N];
int lowtime[N];
int timer=0;
int n,m;

void dfs(int src,int par)
{
  // cout<<par<<" "<<src<<endl;
  timer++;
  intime[src]=timer;
  lowtime[src]=timer;

  int child=0;
  bool isarti=0;

  for(auto it:G[src])
  {
    if(it==par)
      continue;
    child++;
    if(!intime[it])
    {
      dfs(it,src);
      lowtime[src]=min(lowtime[src],lowtime[it]);
      if(lowtime[it]>=intime[src])
      {
        //it is new component
        isarti=1;
      }
      if(lowtime[it]>intime[src])
      {
        //src --it is bridge
        cout<<"bridge"<<"---"<<src<<" "<<it<<endl;
      }
    }
    else                  //intime<timer backedge
        lowtime[src]=min(lowtime[src],intime[it]);


  }
  // if lowtime >=intime then articulation point
  if((par==-1 && child>1)|| (par!=-1 && isarti))
  {
    //src is articulation point
    cout<<src<<endl;
  }
}


void solve()
{
  cin>>n>>m;
  for(int i=0;i<=n;i++)
  {
    lowtime[i]=0;
    intime[i]=0;
  }

  for(int i=0;i<m;i++)
  {
    int x,y;
    cin>>x>>y;
    G[x].pb(y);
    G[y].pb(x);
  }
  dfs(0,-1);
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
