#include<bits/stdc++.h>
using namespace std;
#define mx 200005
vector <int> adj[mx];
void addedge(int u,int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}
int mark[mx];
int add[mx];
int done[mx];
int parent[mx];
void dfs2(int u)
{
	for(int j=0;j<adj[u].size();j++)
	{
		mark[adj[u][j]]=1;
	}
}
void dfs(int u,int par)
{
	parent[u]=par;
	if(par!=-1)
	{
	if(add[par]==1)
		{
			done[u]=1;
			//cout<<u<<endl;
		}
	}

	for(int i=0;i<adj[u].size();i++)
	{
		int v=adj[u][i];
		if(v==par)
			continue;
		dfs(v,u);
	}
	if(done[u]==0 )
		{
			add[par]=1;
			done[u]=1;
			done[par]=1;
			done[parent[par]]=1;
			//cout<<u<<"*"<<par<<" "<<parent[par]<<endl;
		}
}	
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	memset(done,0,sizeof(done));
	memset(add,0,sizeof(add));
	memset(mark,0,sizeof(mark));
	int n;
	cin>>n;
	for(int i=0;i<n-1;i++)
	{
		int u,v;
		cin>>u>>v;
		addedge(u,v);
	}
	dfs(1,-1);
	dfs2(1);
	int final=0;
	for(int i=2;i<=n;i++)
	{
		if(add[i]==1 && mark[i]==0)
			{
			//cout<<i<<"***"<<endl;
			final++;
			}
	}
	cout<<final<<endl;
}