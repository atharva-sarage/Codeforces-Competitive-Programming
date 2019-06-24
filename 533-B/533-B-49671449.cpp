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
# define mx 200005
# define ll long long 
# define db double
# define inf 1e9
# define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
ll dp[mx][3],p[mx];
vector <ll> adj[mx];
void dfs(ll u)
{
	dp[u][1]=dp[u][0]=0;
	for(auto k:adj[u])
	{
		dfs(k);
		ll temp1=dp[u][1];
		ll temp2=dp[u][0];
		dp[u][1]=max((temp1!=0)?(temp1+dp[k][0]):0,temp2+dp[k][1]);
		dp[u][0]=max(temp2+dp[k][0],(temp1!=0)?(temp1+dp[k][1]):0);		
	}
	dp[u][1]=max(dp[u][1],dp[u][0]+p[u]);
}
int main()
{
	ll n;
	cin>>n;
	for(ll i=1;i<=n;i++)	
	{
		ll x,y;
		cin>>x>>y;
		p[i]=y;
		if(x==-1)continue;
		adj[x].pb(i);
	}
	dfs(1);
	cout<<dp[1][1]<<endl;
}