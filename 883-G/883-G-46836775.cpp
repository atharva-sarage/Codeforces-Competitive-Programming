#include<bits/stdc++.h>
# define mx 300005
# define ff first
# define ss second
# define pb push_back
# define mp make_pair
using namespace std;
vector <int> adjmax[mx];
vector <int> adjmin[mx];
struct edge
{
	int t,id;
	char c;
};
vector <pair<int,edge> > adj[mx];
char final1[mx],final2[mx];
bool visited[mx],valid[mx];
int total=0;
char flip(char a)
{
	if(a=='+')
		return '-';
	return '+';
}
void dfs1(int u,int par)
{
	visited[u]=true;
	for(auto k:adj[u])
	{
		if(visited[k.ff] || k.ff==par)continue;
		if(k.ss.t==2)
		{
			final1[k.ss.id]=k.ss.c;
			adjmax[u].pb(k.ff);
		}
		dfs1(k.ff,u);
	}
}
void dfs3(int u,int par)
{
	visited[u]=true;
	for(auto k:adj[u])
	{
		if(visited[k.ff] || k.ff==par)continue;
		if(k.ss.t==2)
		{
			final2[k.ss.id]=flip(k.ss.c);
			adjmin[k.ff].pb(u);
		}
		else
			dfs3(k.ff,u);
	}
}
void dfs2(int u,int par,vector <int>adj[])
{
	visited[u]=true;
	total++;
	for(auto k:adj[u])
	{
		if(visited[k] || k==par)continue;
		dfs2(k,u,adj);
	}
}
int main()
{
	int n,m,s;
	cin>>n>>m>>s;
	for(int i=0;i<m;i++)
	{
		int t,x,y;
		cin>>t>>x>>y;

		if(t==1)
		{
			edge e1={t,i,'?'};
			adj[x].pb(mp(y,e1));
			adjmax[x].pb(y);
			adjmin[x].pb(y);
		}
		else
		{
			valid[i]=true;
			edge e1={t,i,'+',};
			edge e2={t,i,'-',};
			adj[x].pb(mp(y,e1));
			adj[y].pb(mp(x,e2));
		}
		final1[i]='+';
		final2[i]='+';
	}
	for(int i=0;i<=n;i++)
		visited[i]=false;
	dfs1(s,-1);
	for(int i=0;i<=n;i++)
		visited[i]=false;
	dfs2(s,-1,adjmax);
	cout<<total<<endl;
	for(int i=0;i<m;i++)
	{
		if(valid[i])
			cout<<final1[i];
	}
	cout<<endl;
	total=0;
	for(int i=0;i<=n;i++)
		visited[i]=false;
	dfs3(s,-1);
	for(int i=0;i<=n;i++)
		visited[i]=false;
	dfs2(s,-1,adjmin);
	cout<<total<<endl;
	for(int i=0;i<m;i++)
	{
		if(valid[i])
			cout<<final2[i];
	}
	cout<<endl;

}