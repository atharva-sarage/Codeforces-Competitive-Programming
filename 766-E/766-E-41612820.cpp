// nice one

#include<bits/stdc++.h>
using namespace std;
#define mx 100005
typedef int long long ll;
vector<ll> adj[mx];
ll dp[mx][30];
ll below[mx];
ll val[mx][30];
ll ans=0;
void addedge(ll u,ll v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}
void dfs(ll u,ll par)
{
	below[u]=1;
	for(ll i=0;i<26;i++)
		dp[u][i]=val[u][i];

	for(ll i=0;i<adj[u].size();i++)
	{
		ll v=adj[u][i];
		if(v==par)
			continue;
		dfs(v,u);
		for(ll j=0;j<26;j++)
		{
			ans+=(1<<j)*dp[u][j]*(below[v]-dp[v][j]);
			ans+=(1<<j)*dp[v][j]*(below[u]-dp[u][j]);

			if(val[u][j]==0)
				dp[u][j]+=dp[v][j];
			else
				dp[u][j]+=below[v]-dp[v][j];
		}
		below[u]+=below[v];
	}
}
int main()
{
	ll n,x,i,j,u,v;
	cin>>n;
	
	for(i=1;i<=n;i++)
	{
		cin>>x;
		ans+=x;
		j=0;
		while(x)
		{
			if(x%2)
			{
				val[i][j]=1;
			}
			j++;
			x/=2;
		}
	}
	for(i=1;i<n;i++)
	{
		cin>>u>>v;
		addedge(u,v);
	}
	dfs(1,-1);
	cout<<ans<<endl;
}