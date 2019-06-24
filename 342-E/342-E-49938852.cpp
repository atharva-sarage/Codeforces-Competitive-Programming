/****************************
*	Author-Atharva Sarage 	*
*		IIT HYDERABAD     	*
****************************/
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
# define mx 100005
# define D 23
set <int> adj[mx];
int par[25][mx],depth[mx],sub[mx],p[mx],n,ans[mx],nn;
void addedge(int u,int v)
{
	adj[u].insert(v);
	adj[v].insert(u);
}
void dfs1(int u,int parent,int level)
{
	par[0][u]=parent;
	depth[u]=level;
	for(auto k:adj[u])
	{
		if(k==parent)continue;
		dfs1(k,u,level+1);
	}
}
void preprocess()
{
	dfs1(1,-1,0);
	for(int  d=1;d<=D;d++)
		for(int i=0;i<n;i++)
			{ 
				int  mid=par[d-1][i];
				if(mid!=-1)
				par[d][i]=par[d-1][mid];
			}		
}
int  walk(int  i,int  k)
{
	for(int  d=0;d<=D;d++)
	{
		if((k & 1<<d )>0)
			i=par[d][i];
	}
	return i;
}
int  lca(int  i,int  j)
{
	if(depth[i]>depth[j])
		i=walk(i,depth[i]-depth[j]);
	if(depth[i]<depth[j])
		j=walk(j,depth[j]-depth[i]);
	if(i==j)
		return i;
	for(int  d=D;d>=0;d--)
	{
		if(par[d][i]!=par[d][j])
		{
			i=par[d][i];
			j=par[d][j];
		}
	}
	return par[0][i];
}
int  dist(int  i,int  j)
{
	return depth[i]+depth[j]-2*depth[lca(i,j)];
}
// decomposition 
void getsub(int u,int par)
{
	sub[u]=1;nn++;
	for(auto k:adj[u])
	{
		if(k==par)continue;
		getsub(k,u);
		sub[u]+=sub[k];
	}
	//cout<<u<<" "<<sub[u]<<endl;
}
int getcentroid(int u,int par)
{
	for(auto k:adj[u])
	{
		if(k==par)continue;
		if(sub[k]>nn/2)
			return getcentroid(k,u);
	}
	return u;
}
void decompose(int u,int parent)
{
	nn=0;
	getsub(u,-1);
	int centroid=getcentroid(u,parent);
	//cout<<centroid<<" "<<u<<endl;
	p[centroid]=parent;
	for(auto k:adj[centroid])
		{
			adj[k].erase(centroid);
			decompose(k,centroid);
		}
	adj[centroid].clear();
}
// queries
void update(int u)
{
	ans[u]=0;
	int x=u;
	u=p[u];
	while(u!=-1)
	{
		ans[u]=min(ans[u],dist(x,u));
		u=p[u];
	}
	
}
int query(int u)
{
	int x=u;
	int final=ans[x];
	u=p[u];
	while(u!=-1)
	{
		final=min({final,ans[u]+dist(u,x)});
		u=p[u];
	}
	return final;
}
void init()
{
	memset(depth,0,sizeof(depth));
	memset(par,-1,sizeof(par));
	for(int i=0;i<mx;i++)
		ans[i]=inf;
}
int main()
{
	IOS;
	int m;
	cin>>n>>m;
	for(int i=0;i<n-1;i++)
	{
		int x,y;
		cin>>x>>y;
		x--;y--;
		addedge(x,y);
	}
	init();
	preprocess();
	decompose(1,-1);
	update(0);
	for(int i=0;i<m;i++)
	{
		int t,v;
		cin>>t>>v;
		v--;
		if(t==1)
			update(v);
		else
			cout<<query(v)<<endl;
	}
	return 0;
}