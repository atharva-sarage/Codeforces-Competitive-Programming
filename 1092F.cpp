#include<bits/stdc++.h>
using namespace std;
# define mx 200005
typedef int long long ll;
vector <ll> adj[mx];
ll dp[mx],ans[mx],final=0,a[mx];
void addedge(ll u,ll v)
{
	adj[u].push_back(v);	
	adj[v].push_back(u);
}
void dfs(ll u,ll par,ll d)
{
	dp[u]=a[u];
	final+=a[u]*(d);
	for(auto k:adj[u])
	{
		if(k==par)continue;
		dfs(k,u,d+1);;
		dp[u]+=dp[k];
	}
}
void dfs2(ll u,ll par)
{
	for(auto k:adj[u])
	{
		if(k==par)continue;
		ans[k]=ans[u]+dp[1]-2*dp[k];
		dfs2(k,u);
	}
}
int main()
{
	ll n,max1=0;
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(ll i=0;i<n-1;i++)
	{
		ll x,y;
		cin>>x>>y;addedge(x,y);
	}
	dfs(1,-1,0);
	ans[1]=final;
	dfs2(1,-1);
	for(ll i=1;i<=n;i++)
		max1=max(max1,ans[i]);
	cout<<max1<<endl;
}