#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
const int N=1e5+5;

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

  void unionx(int x,int y){
    x=find(x);
    y=find(y);
    if(x==y)
      return;
    if(rank[x]>rank[y])
      swap(x,y);
    par[x]=y;
    rank[y]+=rank[x];
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


int main()
{
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("IN", "r", stdin);
  freopen("OUT", "w", stdout);
  #endif

  int n;
  cin>>n;
  unionfind u(n);
  for(int i=1;i<n;i++)
  {
    int x,y;
    cin>>x>>y;
    u.unionx(x,y);
    u.print();
  }

  return 0;
}
