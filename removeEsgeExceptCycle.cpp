#include<bits/stdc++.h>
#include <iostream>
#include<string>
using namespace std;
#define int long long
#define fi first
#define se second
#define pb push_back
#define ppb pop_back
#define endl '\n'

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(x) (x).begin(), (x).end()


typedef pair < int, int > pii;

// cout << std::setprecision(6) << fixed << bs(0,mx) << endl;
int gcd(int a, int b) { if (b == 0) return a;if(a==0)return b; return gcd(b, a % b); }
int fastpowMOD(int a, int p, int MOD) { if (p == 0) return 1; int z = fastpowMOD(a, p / 2, MOD); z = (z * z) % MOD; if (p % 2) z = (z * a) % MOD; return z; }
int fastpow(int a, int p) { if (p == 0) return 1; int z = fastpow(a, p / 2); z = (z * z); if (p % 2) z = (z * a); return z; }

vector <int> sprime;
vector<bool> prime (1000009, true);
void sieve(int n)
{
	//O(nloglogn) time
	// sprime.pb(0);
	prime[0] = prime[1] = false;
	int cnt=0;
	for (int i=2; i<=n; ++i)
	{
		if (prime[i])
		{
			cnt++;
			sprime.pb(i);
			for (int j=i*i; j<=n; j+=i)
				prime[j] = false;
		}
	}
}

//***********************************************************************//
const int N=1e5+5;
const int mod=1e9+7;
const int M=1e9+7;
const int mod2= 998244353;
const int inf=1e12;
const int mx=1e10;
//in set map use s.count(key)
//binary_search(all(vec), key) in sorted array
//print binary  cout << bitset<20>(n) << "\n";
//cout << oct << n << "\n" and cout << hex << n << "\n" cout << dec
//int x = min({a, b, c, d});
//pi=acos(-1)

#define ld long double
ld eps=1e-9;

//check reachablity from x-->y in directed graph


//dfs in adjacency matrix
int n,m;
vector<int>G[N];
int vis[N];
int deg[N];

void remove()
{
  queue<int>q;
  for(int i=1;i<=n;i++)
  {
    if(deg[i]<=1)
    {
      vis[i]=1;
      q.push(i);
    }
  }

  while(!q.empty())
  {
    int u=q.front();
    q.pop();
    for(auto v:G[u])
    {
      if(!vis[v])
      {
        deg[v]--;
        if(deg[v]<=1)
        {
          vis[v]=1;
          q.push(v);
        }
      }
    }
  }
  for(int i=1;i<=n;i++)
  {
    if(!vis[i])
      cout<<i<<" ";
  }
  cout<<endl;
}



void solve()
{
  cin>>n>>m;
	for(int i=0;i<=n;i++)
	{
		deg[i]=0;
    vis[i]=0;
		G[i].clear();
	}

  for(int i=0;i<m;i++)
  {
    int x,y;
    cin>>x>>y;
    G[x].push_back(y);
    G[y].push_back(x);
    deg[x]++;
    deg[y]++;
  }
  remove();
}


int32_t main()
{
  freopen("IN", "r", stdin);
  freopen("OUT", "w", stdout);

	IOS
  int z=1;
 	cin>>z;
	// string s;
  // getline(cin,s);
	int i=1;
  while(z--)
	{
		// cout<<"Case #"<<i<<": ";
    solve();
		i++;
	}
  return 0;
}
