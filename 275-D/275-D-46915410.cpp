#include<bits/stdc++.h>
using namespace std;
# define mx 100005
# define ll long long
vector <ll> adj[mx];
ll valpos[mx],valneg[mx],dp[mx],a[mx],val[mx];
void addedge(ll u,ll v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}
void dfs(ll u,ll par)
{	
	for(auto k:adj[u])
	{
		if(k==par)continue;
		
		dfs(k,u);
		valneg[u]=max(valneg[u],valneg[k]);
		valpos[u]=max(valpos[u],valpos[k]);
	}
	ll temp=val[u]-valneg[u]+valpos[u];	
	if(temp>0)
		valneg[u]+=temp;
	else
		valpos[u]-=temp;
}
int main()
{
	ll n;
	cin>>n;
	for(ll i=0;i<n-1;i++)
	{
		ll x,y;
		cin>>x>>y;
		addedge(x,y);
	}
	for(ll i=1;i<=n;i++)
		cin>>val[i];
	dfs(1,-1);
	
	cout<<valpos[1]+valneg[1]<<endl;
}