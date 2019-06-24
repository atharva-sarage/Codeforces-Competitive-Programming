#include<bits/stdc++.h>
# define mx 123457
using namespace std;
vector <int> adj[mx];
int depth1[mx],depth2[mx],a[mx];
bool mark[mx];
int e=-1,root,maxlevel=0,dia=0;
void addedge(int u,int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}
int dfs1(int u,int par,int level)
{
	bool c=false;
	if(mark[u])
		c=true;
	for(auto k:adj[u])
	{
		if(k==par)continue;
			c=c|dfs1(k,u,level+1);
	}
	mark[u]=c;
	if(mark[u]==true)
		{
			if(level>maxlevel)
				{root=u;maxlevel=level;}
			e++;
		}
	return c;
}
void dfs(int u,int par,int level,int depth[] )
{
	if(!mark[u])return;
	depth[u]=level;
	dia=max(dia,level);
	for(auto k:adj[u])
	{
		if(k==par)continue;
		dfs(k,u,level+1,depth);
	}
}
int main()
{
	memset(depth1,-1,sizeof(depth1));
	memset(depth2,-1,sizeof(depth1));
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n-1;i++)
	{
		int x,y;
		cin>>x>>y;
		addedge(x,y);
	}
	for(int i=0;i<m;i++)
		{
			int x;
			cin>>x;
			mark[x]=true;
			root=x;
		}
	dfs1(root,-1,0); // finds deepest node
	dfs(root,-1,0,depth1); // get diameter length
	for(int i=1;i<=n;i++)
	{
		if(depth1[i]==dia)
			root=i;
	}	
	dfs(root,-1,0,depth2);
	int mini=n+5;
	for(int i=1;i<=n;i++)
	{
		if(depth1[i]==dia || depth2[i]==dia)
			mini=min(mini,i);
	}
	cout<<mini<<endl;
	cout<<2*e-dia<<endl;

}