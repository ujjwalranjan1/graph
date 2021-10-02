
#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
using pii=pair<int,int>;


#ifndef ONLINE_JUDGE
#define debarr(a,n)cerr<<#a<<":";for(int i=0;i<n;i++)cerr<<a[i]<<" ";cerr<<endl;
#define debmat(mat,row,col)cerr<<#mat<<":\n";for(int i=0;i<row;i++){for(int j=0;j<col;j++)cerr<<mat[i][j]<<" ";cerr<<endl;}
#define pr(...)dbs(#__VA_ARGS__,__VA_ARGS__)
template<class S,class T>ostream &operator<<(ostream &os,const pair<S,T> &p){return os<<"("<<p.first<<","<<p.second<<")";}
template<class T>ostream &operator<<(ostream &os,const vector<T> &p){os<<"[";for(auto&it:p)os<<it<<" ";return os<<"]";}
template<class T>ostream &operator<<(ostream &os,const set<T>&p){os<<"[";for(auto&it:p)os<<it<<" ";return os<<"]";}
template<class T>ostream &operator<<(ostream &os,const multiset<T>&p){os<<"[";for(auto&it:p)os<<it<<" ";return os<<"]";}
template<class S,class T>ostream &operator<<(ostream &os,const map<S,T>&p){os<<"[";for(auto&it:p)os<<it<<" ";return os<<"]";}
template<class T>void dbs(string str,T t){cerr<<str<<":"<<t<<"\n";}
template<class T,class...S>void dbs(string str,T t,S... s){int idx=str.find(',');cerr<<str.substr(0,idx)<<":"<<t<<",";dbs(str.substr(idx+1),s...);}
#endif


//fi for vertex //se for distance
class prioritize
{
  public:bool operator()(pii &p1,pii &p2)
  {
    //priority queue top means vector last //
    //p1 comes first out of priority queue means its at last in vector
    return p1.se>p2.se;
  }
};

const int N=1e5+5;
vector<pii >G[N];
int dist[N];
bool vis[N];
int n,m;


void dijkstra(int sc)
{
  for(int i=0;i<=n;i++)
  {
    dist[i]=1e9;
    vis[i]=0;
  }

  priority_queue<pii,vector<pii>,prioritize> pq;
  dist[sc]=0;
  pq.push(make_pair(sc,0));
  while(!pq.empty())
  {
    pii u=pq.top();
    pq.pop();
    if(vis[u.fi])
      continue;
    vis[u.fi]=1;
    for(auto v:G[u.fi])
    {
      if(dist[v.fi]>u.se+v.se)
      {
        dist[v.fi]=u.se+v.se;
        pq.push(make_pair(v.fi,u.se+v.se));
      }
    }
  }
  debarr(dist,n+1);
}

int main()
{
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("IN", "r", stdin);
  freopen("OUT", "w", stdout);
  #endif

  cin>>n>>m;
  for(int i=0;i<m;i++)
  {
    int x,y,z;
    cin>>x>>y>>z;
    G[x].push_back({y,z});
    G[y].push_back({x,z});
  }
  int sc;
  cin>>sc;
  dijkstra(sc);
  return 0;
}
