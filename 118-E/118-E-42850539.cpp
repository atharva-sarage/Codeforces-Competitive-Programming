// finally
#include<bits/stdc++.h>
using namespace std;
# define mx 300005
vector <pair<int,int> > adj[mx];
vector <int> adj2[mx];
int visited[mx];
int parent[mx];
int edge[mx];
vector <pair<int,int> > edges;
int timein[mx];
int timeout[mx];
int t1=0;
void addedge(int u,int v,int w)
{
	adj[u].push_back(make_pair(v,w));
	adj[v].push_back(make_pair(u,w));
	adj2[u].push_back(v);
	adj2[v].push_back(u);
}
void dfs(int u,int par,vector<pair<int,int> > adj[] )
{
	visited[u]=true;
	timein[u]=t1++;
	for(int i=0;i<adj[u].size();i++)
	{
		int v=adj[u][i].first;
		int w=adj[u][i].second;
		if(v==par)
			continue;
	    if(!visited[v])
		{
			edge[w]=1;
			cout<<u+1<<" "<<v+1<<endl;
			parent[v]=u;
			dfs(v,u,adj);
		}					
	}
	timeout[u]=t1++;
}
int low[mx];
int val[mx];
int t=0;
int flag=0;
void check(int u,int par,vector <int> adj[])
{
	if(flag==1)
		return;
	low[u]=t;
	val[u]=t;
	t++;
	for(int i=0;i<adj[u].size();i++)
	{
		int v=adj[u][i];
		if(v==par)
			continue;
		else if(val[v]==-1)
		{
			parent[v]=u;
			check(v,u,adj2);
			if(low[v]>val[u])
				flag=1;
		}
		
		low[u]=min(low[u],low[v]);
	}

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	memset(val,-1,sizeof(val));
	memset(edge,0,sizeof(edge));
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int x,y;
		cin>>x>>y;
		x--;y--;
		addedge(x,y,i);
		edges.push_back(make_pair(x,y));
	}
	check(0,-1,adj2);
	if(flag==1)
		{
		cout<<0<<endl;
		return 0;
		}
	dfs(0,-1,adj);
	for(int i=0;i<m;i++)
		{
			if(edge[i]==0)
			{
				int u=edges[i].first;
				int v=edges[i].second;
				if(timein[u]<=timein[v] && timeout[v]<=timeout[u])
					cout<<v+1<<" "<<u+1<<endl;
				else
					cout<<u+1<<" "<<v+1<<endl;
			}
		}
}