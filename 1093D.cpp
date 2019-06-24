#include<bits/stdc++.h>
using namespace std;
# define mx 300005
# define mod 998244353
# define pb push_back
typedef int long long ll;
vector <ll> adj[mx];
ll visited[mx],colour[mx],flag=0;
vector <ll> vec;
ll n,m,final=1;
ll pow1(ll a, ll b)
{
    ll x=1,y=a;
    while(b > 0)
    {
        if(b%2 == 1)
        {
            x=(x*y);
            if(x>mod) x%=mod;
        }
        y = (y*y);
        if(y>mod) y%=mod;
        b /= 2;
    }
    return x%mod;
}
void addedge(ll u,ll v)
{
	adj[u].pb(v);
	adj[v].pb(u);
}
void dfs(ll u,ll par,ll col)
{
	visited[u]=true;
	colour[u]=col;
	vec.pb(u);
	for(auto k:adj[u])
	{
		if(k==par)continue;
		if(visited[k] && colour[k]!=1-col)
			{flag=1;continue;}
		else if(visited[k])continue;
		dfs(k,u,1-col);
	}
}
void DFS()
{
	for(int i=1;i<=n;i++)
	{
		if(visited[i])continue;
		dfs(i,-1,0);
		if(flag==1)
		{
			vec.clear();
			return;
		}
		int c1=0;
		for(auto k:vec)
		{
			if(colour[k]==0)
				c1++;
		}
		final=(final*(pow1(2,c1)+pow1(2,vec.size()-c1)%mod))%mod;
		vec.clear();
	}
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll t;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		flag=0;final=1;
		for(int i=0;i<=n;i++)
		{
			visited[i]=false;
			colour[i]=-1;
		}
		for(ll i=0;i<m;i++)
		{
			ll x,y;
			cin>>x>>y;
			addedge(x,y);
		}
		DFS();
		if(flag==1)
			cout<<0<<endl;
		else
			cout<<final<<endl;
		for(int i=1;i<=n;i++)
			adj[i].clear();		
	}
}