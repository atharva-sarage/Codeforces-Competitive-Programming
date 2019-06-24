#include<bits/stdc++.h>
# define mx 200005
using namespace std;
int visited[mx],visited2[mx],c[mx];
vector<int> adj[mx];
vector <int> adj2[mx];
int s;
void addedge(int u,int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}
void addedge2(int u,int v)
{
	adj2[u].push_back(v);
	adj2[v].push_back(u);
}

void dfs1(int u,int par,int g,int col)
{
	visited[u]=true;
	if(col==-1)
		col=c[u];
		
	for(int i=0;i<adj[u].size();i++)
	{
		int v=adj[u][i];
		if(v==par || visited[v])
			continue;
		else if(c[v]==col)
			{
				dfs1(v,u,g,c[v]);
			}	
		else
			{
			addedge2(g,v);
			s=v;
			dfs1(v,u,v,c[v]);
			}
	}
}
int maxc=0;
void dfs(int u,int par,int count)
{
	visited2[u]=true;
	count++;
	for(int i=0;i<adj2[u].size();i++)
	{
		int v=adj2[u][i];
		if(v==par || visited2[v])
			continue;
		if(count>=maxc)
			{
				maxc=count;
				s=v;
			}
		dfs(v,u,count);
	}
}
int main()
{
	
	int n,m;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	for(int i=0;i<n-1;i++)
	{
		int x,y;
		cin>>x>>y;
		addedge(x,y);
	}
	dfs1(1,-1,1,-1);
	dfs(s,-1,0);
	maxc=0;
	memset(visited2,false,sizeof(visited2));
	dfs(s,-1,0);
	//cout<<maxc<<endl;
	cout<<(maxc+1)/2<<endl;


}