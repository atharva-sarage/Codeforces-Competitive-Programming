#include<bits/stdc++.h>
# define mx 300005
# define ff first
# define ss second
# define pb push_back
# define mp make_pair
using namespace std;
typedef int long long ll;
vector <pair<ll,ll> > adj[mx];
ll val[mx],a[mx],deg[mx],final=0;
void addedge(ll u,ll v,ll w)
{
	adj[u].pb(mp(v,w));
	adj[v].pb(mp(u,w));
}
ll dfs(ll u,ll par)
{
	ll temp2=0,temp1,max1=0,max2=0;
	for(auto k:adj[u])
	{
		if(k.ff==par)continue;
		ll temp1=-k.ss+dfs(k.ff,u);
		if(temp1>=max1)
		{
			max2=max1;
			max1=temp1;
		}
		else if(temp1>max2)
		{
			max2=temp1;
		}		
	}
	final=max(final,max1+max2+a[u]);
	return max1+a[u];
}
int main()
{
	ll n;
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
		
		val[i]=a[i];
	}
	for(ll i=0;i<n-1;i++)
	{
		ll x,y,z;
		cin>>x>>y>>z;
		addedge(x,y,z);
		
	}
	dfs(1,-1);
	if(n==1)
		final=a[1];
	cout<<final<<endl;
}