
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

vector<int>G[N];
int indeg[N];
  int n,m;
vector<int>topo;

void kahn()
{
  // queue<int>q;
  priority_queue<int,vector<int>,greater<int> >q;
  for(int i=1;i<=n;i++)
  {
    if(indeg[i]==0)
      q.push(i);
  }

  while(!q.empty())
  {
    int u=q.top();
    topo.push_back(u);
    q.pop();
    for(auto v:G[u])
    {
      indeg[v]--;
      if(indeg[v]==0)
        q.push(v);
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

  for(int i=0;i<=n;i++)
  {
    G[i].clear();
    indeg[i]=0;
  }

  for(int i=0;i<m;i++)
  {
    int x,y;
    cin>>x>>y;
    G[x].push_back(y);
    indeg[y]++;
  }
  kahn();
  for(auto it:topo)
    cout<<it<<" ";
  cout<<endl;
  return 0;
}
