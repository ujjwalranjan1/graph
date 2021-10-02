
#include<bits/stdc++.h>
using namespace std;


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

vector<string>g;
int n,m;
using state=pair<int,int>;
int dist[1005][1005];

#define fi first
#define se second

int x[]={1,0,-1,0};
int y[]={0,-1,0,1};

map<char,state>mp;

bool check(state s)
{
  if(s.fi>=0 && s.fi<n && s.se>=0 && s.se<m)
    return 1;
  return 0;
}



void bfs01(state s)
{
  dist[s.fi][s.se]=0;
  deque<state>dq;
  dq.push_back(s);
  while(!dq.empty())
  {
    state u=dq.front();
    dq.pop_front();
    for(int i=0;i<4;i++)
    {
      state v={u.fi+x[i],u.se+y[i]};
      int cost=mp[g[u.fi][u.se]]==make_pair(x[i],y[i])?0:1;
      if(check(v) && dist[v.fi][v.se]>dist[u.fi][u.se]+cost)
      {
        dist[v.fi][v.se]=dist[u.fi][u.se]+cost;
        if(cost==0)
          dq.push_front(v);
        else
          dq.push_back(v);
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
  mp['u']={-1,0};
  mp['d']={1,0};
  mp['l']={0,-1};
  mp['r']={0,1};
  cin>>n;
  for(int i=0;i<n;i++)
  {
    string s;
    cin>>s;
    m=s.size();
    g.push_back(s);
  }
  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
      dist[i][j]=1e9;
  bfs01(make_pair(0,0));

  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
      cout<<dist[i][j]<<" ";
    cout<<endl;
  }
  return 0;
}
