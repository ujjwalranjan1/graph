
#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second


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

using iii=pair<pair<int,int>,int>;


const int N=1e5+5;

int dist[1005];
vector<iii>edgelist;

int n,m;

void bellman(int sc)
{
  for(int i=0;i<n;i++)
    dist[i]=1e9;
  dist[sc]=0;

  for(int i=0;i<n-1;i++)
  {
    for(auto e:edgelist)
    {
      int u=e.fi.fi;
      int v=e.fi.se;
      int cost=e.se;
      if(dist[v]>dist[u]+cost)
        dist[v]=dist[u]+cost;
    }
  }

  debarr(dist,n);
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
    edgelist.push_back({{x,y},z});
  }
  bellman(0);

  return 0;
}
