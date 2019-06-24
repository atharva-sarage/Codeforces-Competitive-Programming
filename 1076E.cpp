// easy peasy lemon squeezy
#include<bits/stdc++.h>
using namespace std;
# define mx 300005
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef int long long ll;
struct query
{
	ll d,x;
};
vector <ll> adj[mx];
vector <query> q[mx];
ll dp[mx]={0};
ll final[mx],n;
void addedge(ll u,ll v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}
void dfs(ll u,ll sum,ll level,ll parent)
{
	for(ll i=0;i<q[u].size();i++)
	{
		query v=q[u][i];
		dp[min(n,v.d+level)]+=v.x;
		sum+=v.x;
	}
	final[u]=sum;
	for(ll i=0;i<adj[u].size();i++)
	{
		ll v=adj[u][i];
		if(v!=parent)
			dfs(v,sum-dp[level],level+1,u);
	}
	for(ll i=0;i<q[u].size();i++)
	{		
		query v=q[u][i];
		dp[min(n,v.d+level)]-=v.x;
	}
}
int main()
{
	IOS;
	ll sum=0;
	cin>>n;
	for(ll i=0;i<n-1;i++)
	{
		ll x,y;
		cin>>x>>y;
		x--;y--;
		addedge(x,y);
	}
	ll m;
	cin>>m;
	for(ll i=0;i<m;i++)
	{
		ll x,y,z;
		cin>>x>>y>>z;
		y=min(n,y);
		x--;
		q[x].push_back({y,z});		
	}
	dfs(0,0,0,-1);
	for(ll i=0;i<n;i++)
		cout<<final[i]<<" ";
}