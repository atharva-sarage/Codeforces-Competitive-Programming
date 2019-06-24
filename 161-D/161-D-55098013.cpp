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
# define mx2 505
# define mx 100005
vector <ll> adj[mx];
void addedge(ll u,ll v)
{
	adj[u].pb(v);
	adj[v].pb(u);
}
ll dp[mx][mx2]; // no of vertices at depth j from i
ll k,ans=0;
void dfs(ll u,ll par)
{
	dp[u][0]=1;
	for(auto v:adj[u])
	{
		if(v==par)continue;
		dfs(v,u);
		for(ll i=0;i<k;i++)
			dp[u][i+1]+=dp[v][i];		
	}
	ll temp1=dp[u][k];
	ll temp2=0;
	// cout<<u<<" "<<" : "<<ans<<" ";
	for(auto v:adj[u])	
	{
		if(v==par)continue; // all paths such that lca is u 
		for(ll i=0;i<k-1;i++)
			temp2+=dp[v][i]*(dp[u][k-1-i]-dp[v][k-i-2]);			
	}	
	ans+=temp1+temp2/2;
	// cout<<u<<" "<<" :??  "<<ans<<" ";
	// for(ll i=0;i<=k;i++)
	// 	cout<<dp[u][i]<<" ";
}

int main()
{
	IOS;
	ll n;
	cin>>n>>k;
	for(ll i=0;i<n-1;i++)	
	{
		ll x,y;
		cin>>x>>y;
		addedge(x,y);
	}
	dfs(1,-1);
	cout<<ans<<endl;
}