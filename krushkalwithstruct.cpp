
#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
const int N=1e5+5;

vector<pair<int,pair<int,int> > >edges;
int cost=0;

struct unionfind{
  int n;
  int *par,*rank;
  unionfind(int m){
    n=m;
    par=new int[n+1];
    rank=new int[n+1];
    for(int i=0;i<=n;i++)
      par[i]=i,rank[i]=1;
  }
  ~unionfind(){
    delete[] par;
    delete[] rank;
  }

  int find(int v){
    if(v==par[v])
      return v;
    return par[v]=find(par[v]);
  }

  void unionx(int x,int y,int z){
    x=find(x);
    y=find(y);
    if(x==y)
      return;
    if(rank[x]>rank[y])
      swap(x,y);
    par[x]=y;
    rank[y]+=rank[x];
    cout<<x<<" "<<y<<endl;
    cost+=z;
  }

  void reset(){
    for(int i=0;i<=n;i++)
      par[i]=i,rank[i]=1;
  }

  void print(){
    cout<<"parent:";
    for(int i=0;i<n;i++)
      cout<<par[i]<<" ";
    cout<<endl;

    cout<<"rank:";
    for(int i=0;i<n;i++)
      cout<<rank[i]<<" ";
    cout<<endl;
  }

  int findsize(){
    return n;
  }

};


void solve()
{
  int n,m;
  cin>>n>>m;
  unionfind uf(n);
  for(int i=0;i<m;i++)
  {
    int x,y,z;
    cin>>x>>y>>z;
    edges.push_back({z,{x,y}});
  }
  sort(edges.begin(),edges.end());
  cost=0;

  for(int i=0;i<m;i++)
  {
    int price=edges[i].first;
    int u=edges[i].second.first;
    int v=edges[i].second.second;
    uf.unionx(u,v,price);
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
