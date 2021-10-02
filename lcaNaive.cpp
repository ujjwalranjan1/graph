
#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
const int N=1e5+5;


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

//lca of tree

vector<int>G[N];
int height[N];
int parent[N];

void dfs(int u,int par,int h)
{
  height[u]=h;
  parent[u]=par;
  for(auto v:G[u])
  {
    if(v!=par)
      dfs(v,u,h+1);
  }
}

int lca(int a,int b)
{
  if(height[a]>height[b])
    swap(a,b);
  int d=height[b]-height[a];
  while(height[b]!=height[a])
    b=parent[b];

  if(a==b)
    return a;
  while(parent[a]!=parent[b])
  {
    a=parent[a];
    b=parent[b];
  }
  return parent[a];
}



int main()
{
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("IN", "r", stdin);
  freopen("OUT", "w", stdout);
  #endif
  int n;
  cin>>n;
  for(int i=1;i<n;i++)
  {
    int x,y;
    cin>>x>>y;
    G[x].push_back(y);
    G[y].push_back(x);
  }
  dfs(1,0,0);
  int a,b;
  cin>>a>>b;
  debarr(parent,n+1);
  debarr(height,n+1);
  cout<<lca(a,b);
  return 0;
}
