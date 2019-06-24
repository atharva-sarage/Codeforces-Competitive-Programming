/******************************************
*    AUTHOR:         Atharva Sarage       *
*    INSTITUITION:   IIT HYDERABAD        *
******************************************/
#include<bits/stdc++.h>
#warning Check Max_Limit,Overflows
using namespace std;
# define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
# define ff first
# define ss second
# define pb push_back
# define mod 1000000007
# define ll long long 
# define db double
# define inf 1e9
# define mx2 100005
# define mx 200005
ll dp[mx][2],final=0,ans[mx][2];
vector <pair<ll,ll>> adj[mx];
void addedge(ll u,ll v,ll c)
{
	adj[u].pb({v,c});
	adj[v].pb({u,c});
}
// once done is set to true it will only see for 1's 
void dfs1(ll u,ll par)
{
	for(auto k:adj[u])
	{
		if(k.ff==par)continue;
		dfs1(k.ff,u);
		if(k.ss==0)
			dp[u][0]+=(1+dp[k.ff][0]+dp[k.ff][1]);
		else
			dp[u][1]+=(1+dp[k.ff][1]);				
	}
}
void dfs2(ll u,ll par,ll c)
{
	ans[u][0]=dp[u][0];
	ans[u][1]=dp[u][1]; // subtree take care of

	//cout<<u<<" "<<ans[u][1]<<" "<<ans[u][0]<<"###"<<" "<<c<<" "<<par<<endl;
	if(c==0)
		ans[u][0]+=ans[par][0]+ans[par][1]-dp[u][0]-dp[u][1];
	if(c==1)
		ans[u][1]+=ans[par][1]-dp[u][1];

	final+=ans[u][1]+ans[u][0];
	//cout<<u<<" "<<ans[u][1]<<" "<<ans[u][0]<<endl;
	for(auto k:adj[u])
	{
		if(k.ff==par)continue;
		dfs2(k.ff,u,k.ss);
	}
}
int main()
{
    IOS;
	ll n;
	cin>>n;
	for(ll i=0;i<n-1;i++)
	{
		ll x,y,c;
		cin>>x>>y>>c;
		addedge(x,y,c);
	}
	dp[1][0]=dp[1][1]=0;
	dfs1(1,-1);
	dfs2(1,-1,-1);
	cout<<final<<endl;
}
