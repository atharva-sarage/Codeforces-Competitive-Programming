#include<bits/stdc++.h>
using namespace std;
# define mx 300005
typedef int long long ll;
vector <ll> vec;
vector <ll> adj[mx];
ll dp[mx],a[mx],k=0,max1=LONG_MIN;
void addedge(ll u,ll v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}
void dfs(ll u,ll par,bool keep)
{
	dp[u]=a[u];
	for(auto k:adj[u])
	{
		if(k==par)continue;
		dfs(k,u,keep);
		if(dp[k]>=0)
			dp[u]+=dp[k];
	}
	if(keep)
		max1=max(max1,dp[u]);
	else if(dp[u]==max1)
	{
			dp[u]=0;
			
			k++;
	}
}

int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n;
	cin>>n;
	for(ll i=1;i<=n;i++)
		cin>>a[i];
	for(ll i=0;i<n-1;i++)
	{
		ll x,y;
		cin>>x>>y;
		addedge(x,y);
	}
	dfs(1,-1,1);
	dfs(1,-1,0);
	cout<<k*max1<<" "<<k<<endl;
	
}