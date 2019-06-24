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
int depth[mx],sub[mx],p[mx],n,ans[mx],nn;
void addedge(int u,int v)
{
	adj[u].insert(v);
	adj[v].insert(u);
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
void decompose(int u,int parent,int level)
{
	nn=0;
	getsub(u,-1);
	int centroid=getcentroid(u,parent);
	ans[centroid]=level;
	p[centroid]=parent;
	for(auto k:adj[centroid])
		{
			adj[k].erase(centroid);
			decompose(k,centroid,level+1);
		}
	adj[centroid].clear();
}
int main()
{
	IOS;
	int n;
	cin>>n;
	for(int i=0;i<n-1;i++)
	{
		int x,y;
		cin>>x>>y;
		x--;y--;
		addedge(x,y);
	}
	decompose(1,-1,0);
	for(int i=0;i<n;i++)
		cout<<(char)(ans[i]+'A')<<" ";
	return 0;
}