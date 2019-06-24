#include<bits/stdc++.h>
using namespace std;
# define mx 3005
vector <int> adj[mx];
int visited[mx];
int parent[mx];
int mark[mx];
int dist[mx];
void addedge(int u,int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}
int flag=0;
void dfs(int u,int par)
{
	visited[u]=true;
	parent[u]=par;
	for(int i=0;i<adj[u].size();i++)
	{
		int v=adj[u][i];
		if(v==par)
			continue;
		if(!visited[v])
			dfs(v,u);
		else if(flag!=1)
		{
			mark[v]=true;
			while(u!=v)
			{
				mark[u]=true;
				u=parent[u];
			}
			flag=1;
			return ;
		}
	}
}
void dfs2(int u,int par)
{
	visited[u]=true;
	parent[u]=par;
	for(int i=0;i<adj[u].size();i++)
	{
		int v=adj[u][i];
		if(v==parent[u] || mark[v]==true)
			continue;
		
		if(!visited[v])
		{	
			dist[v]=1+dist[u];
			dfs2(v,u);
		}
	}
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	memset(parent,-1,sizeof(parent));
	int n,m;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		addedge(x,y);
	}
		dfs(1,-1);
	memset(visited,false,sizeof(visited));
	memset(parent,-1,sizeof(parent));
	memset(dist,0,sizeof(dist));

	for(int i=1;i<=n;i++)
	{
		if(mark[i]==true)
		{
			dist[i]=0;
			dfs2(i,-1);
		}
	}
	for(int i=1;i<=n;i++)
	{
		cout<<dist[i]<<" ";
	}
	printf("\n");
}