/**************************
*	Author-Atharva Sarage *
*		IIT HYDERABAD     *
**************************/
#include<bits/stdc++.h>
#warning Check Max_Limit,Overflows
using namespace std;
# define ff first
# define ss second
# define pb push_back
# define mod 1000000007
# define mx 100005
# define ll long long 
# define db double
# define inf 1e9
# define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
ll dp[mx][3];
ll col[mx];
vector <ll> adj[mx];
void addedge(ll u,ll v)
{
	adj[u].pb(v);
}
void dfs(ll u)
{
	ll temp0,temp1;
	if(col[u]==1)
		{dp[u][1]=1;dp[u][0]=0;}
	else
		{dp[u][0]=1;dp[u][1]=0;}
	for(auto v:adj[u])
	{
		// do not cut edge
		dfs(v);
		temp0=temp1=0;
		temp1=(dp[u][0]*dp[v][1])%mod+(dp[u][1]*dp[v][0])%mod;
		temp1%=mod;
		temp0=dp[u][0]*dp[v][0];
		temp0%=mod;
		// cut edge
		temp1+=dp[u][1]*dp[v][1];
		temp1%=mod;
		temp0+=dp[u][0]*dp[v][1];
		temp0%=mod;
		dp[u][1]=temp1;dp[u][0]=temp0;
	}
}
int main()
{
	ll n;
	cin>>n;
	for(ll i=1;i<=n-1;i++)	
	{
		ll x;cin>>x;
		addedge(x,i);
	}
	for(ll i=0;i<n;i++)
		{ll x;cin>>x;col[i]=x;}
	dfs(0);
	cout<<dp[0][1]<<endl;
}