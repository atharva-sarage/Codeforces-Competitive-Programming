#include<bits/stdc++.h>
using namespace std;
# define mx 200005
# define IOS ios::sync_with_stdio(0),cin.tie(0)
typedef int long long ll;
vector <ll> adj[mx];
vector <pair<ll,ll> > edge;
ll sub[mx],level[mx],parent[mx];
void addedge(ll u,ll v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}
void dfs(ll u,ll par)
{
	sub[u]++;
	for(ll i=0;i<adj[u].size();i++)
	{
		ll v=adj[u][i];
		if(v==par)
			continue;
		dfs(v,u);
		sub[u]+=sub[v];
	}
}
void bfs(int u)
{
	queue<int> q;
	q.push(u);
	level[u]=0;
	while(!q.empty())
	{
		int v=q.front();
		q.pop();
		for(int i=0;i<adj[v].size();i++)
		{
			int x=adj[v][i];
			if(x==parent[v])
				continue;

			parent[x]=v;
			level[x]=1+level[v];
			q.push(x);
		}
	}
}
int main()
{
    IOS;
	ll n;
	cin>>n;
	for(ll i=0;i<n-1;i++)
	{
		ll x,y;
		cin>>x>>y;
		x--;y--;
		addedge(x,y);
		edge.push_back(make_pair(x,y));
	}
	dfs(0,-1);
	bfs(0);
	ll ans=0;
	
	for(ll i=0;i<edge.size();i++)
	{
		if(sub[edge[i].first]>sub[edge[i].second])
			ans+=sub[edge[i].second]*(n-sub[edge[i].second]);
		else
			ans+=sub[edge[i].first]*(n-sub[edge[i].first]);

	}
	ll odd=0,even=0;
	for(int i=1;i<=n;i++)
	{
		if(level[i]%2==0)
			even++;
		else
			odd++;
	}
	cout<<(ans+odd*even)/2;
}