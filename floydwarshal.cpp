
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
const int N=1e5+5;

int G[405][405];
int back[405][405];

void printpath(int i,int j)
{
  printpath(i,back[i][j]);
  cout<<j<<endl;
}
int main()
{
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("IN", "r", stdin);
  freopen("OUT", "w", stdout);
  #endif

  int n,m;
  cin>>n>>m;

  for(int i=0;i<=n;i++)
    for(int j=0;j<=n;j++)
    {
      if(i==j)
        G[i][j]=0;
      else
        G[i][j]=100;
      back[i][j]=i;
    }

  for(int i=0;i<m;i++)
  {
    int x,y,z;
    cin>>x>>y>>z;
    G[x][y]=z;
  }




  for(int k=0;k<n;k++)
    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
      {
        if(G[i][j]>G[i][k]+G[k][j])
        {
          G[i][j]=G[i][k]+G[k][j];
          back[i][j]=back[k][j];
        }
      }

  debmat(G,n,n);
  debmat(back,n,n);


  return 0;
}
