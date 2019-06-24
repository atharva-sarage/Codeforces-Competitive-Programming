#include<bits/stdc++.h>
using namespace std;
#define mx 100005
typedef int long long ll;
vector <ll> adj[mx];
int dp[mx];
void addedge(ll u,ll v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}
int main()
{
	ios::sync_with_stdio(0);
	cout.tie(0);
	ll n,m,ans=0;
	cin>>n>>m;
	for(ll i=0;i<m;i++)
	{
		ll u,v;
		cin>>u>>v;
		addedge(u,v);
	}

	for(ll i=1;i<=n;i++)
	{
		dp[i]=1;
	}
	for(ll i=2;i<=n;i++)
	{
		for(ll j=0;j<adj[i].size();j++)
		{
			ll x=adj[i][j];
			if(x<i)
				dp[i]=max(dp[i],1+dp[x]);
		}
	}
	
	for(ll i=1;i<=n;i++)
	{
		ll x1=adj[i].size();
		ans=max(ans,dp[i]*x1);
	}
	cout<<ans<<endl;
}